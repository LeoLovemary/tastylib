#include "tastylib/TextQuery.h"
#include <sstream>
#include <algorithm>

TASTYLIB_NS_BEGIN

TextQuery::TextQuery(std::istream &is) : txt(new std::vector<std::string>) {
    std::string line;
    while (std::getline(is, line)) {
        txt->push_back(line);
        // Replace punctuations with spaces
        std::replace_if(line.begin(), line.end(), isPunc, ' ');
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(txt->size() - 1);
        }
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> empty(new std::set<line_no>);
    auto it = wm.find(word);
    if (it == wm.end()) {
        return QueryResult(word, txt, empty);
    } else {
        return QueryResult(word, txt, it->second);
    }
}

bool TextQuery::isPunc(const char c) {
    return c == '.' || c == ',' || c == '?' || c == '\'' || c == '\"';
}

QueryResult::QueryResult(const std::string &word_,
                         std::shared_ptr<std::vector<std::string>> txt_,
                         std::shared_ptr<std::set<TextQuery::line_no>> lines_)
    : word(word_), txt(txt_), lines(lines_) {}

std::ostream& operator<<(std::ostream &os, const QueryResult &res) {
    os << res.word << ": " << res.lines->size();
    for (const auto line : *(res.lines)) {
        os << " | line " << line + 1 << ": " << res.txt->at(line);
    }
    return os;
}

TASTYLIB_NS_END
