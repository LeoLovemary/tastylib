/*
 * Implementations of the Text-Query program
 * from §12.3 & §15.9, C++ Primer, 5th Edition.
 */
#ifndef TASTYLIB_TEXTQUERY_H_
#define TASTYLIB_TEXTQUERY_H_

#include "tastylib/internal/base.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <memory>
#include <iostream>

TASTYLIB_NS_BEGIN

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    explicit TextQuery(std::istream &is);

    QueryResult query(const std::string &word) const;

private:
    static bool isPunc(const char c);

private:
    // Store each line in the text
    std::shared_ptr<std::vector<std::string>> txt;
    // Map words to line numbers
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream& operator<<(std::ostream &os, const QueryResult &res);

public:
    QueryResult(const std::string &word_,
                std::shared_ptr<std::vector<std::string>> txt_,
                std::shared_ptr<std::set<TextQuery::line_no>> lines_);

private:
    std::string word;  // Word this query represents
    std::shared_ptr<std::vector<std::string>> txt;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
};

TASTYLIB_NS_END

#endif
