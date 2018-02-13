#include "gtest/gtest.h"
#include "tastylib/TextQuery.h"
#include <string>
#include <sstream>

using tastylib::TextQuery;


class TextQueryTest: public ::testing::Test {
protected:

    static void SetUpTestCase() {
        article = new std::string(
            "Alice Emma has long flowing red hair\n"
            "Her Daddy says when the wind blows\n"
            "like a fiery bird in flight.\n"
            "through her hair, it looks almost alive,\n"
            "A beautiful fiery bird, he tells her,\n"
            "magical but untamed.\n"
            "\"Daddy, shush, there is no such thing,\"\n"
            "she tells him, at the same time wanting\n"
            "him to tell her more.\n"
            "Shyly, she asks, \"I mean, Daddy, is there?\"\n"
        );
        lines = new std::vector<std::string>;
        std::istringstream iss(*article);
        std::string line;
        while (std::getline(iss, line)) {
            lines->push_back(line);
        }
    }

    static void TearDownTestCase() {
        delete article; article = nullptr;
        delete lines; lines = nullptr;
    }

protected:
    static std::string *article;
    static std::vector<std::string> *lines;
};

std::string *TextQueryTest::article = nullptr;
std::vector<std::string> *TextQueryTest::lines = nullptr;


TEST_F(TextQueryTest, WordQuery) {
    std::istringstream iss(*article);
    std::ostringstream oss;

    TextQuery tq(iss);

    std::string word = "Alice";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 1" +
              " | line 1: " + lines->at(0));

    word = "Daddy";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 3" +
              " | line 2: " + lines->at(1) +
              " | line 7: " + lines->at(6) +
              " | line 10: " + lines->at(9));

    word = "hair";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 2" +
              " | line 1: " + lines->at(0) +
              " | line 4: " + lines->at(3));

    word = "fiery";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 2" +
              " | line 3: " + lines->at(2) +
              " | line 5: " + lines->at(4));

    word = "bird";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 2" +
              " | line 3: " + lines->at(2) +
              " | line 5: " + lines->at(4));

    word = "wind";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 1" +
              " | line 2: " + lines->at(1));

    word = "her";
    oss.str("");
    oss << tq.query(word);
    ASSERT_EQ(oss.str(),
              word + ": 3" +
              " | line 4: " + lines->at(3) +
              " | line 5: " + lines->at(4) +
              " | line 9: " + lines->at(8));
}
