#ifndef TASTYLIB_CALCULATOR_H_
#define TASTYLIB_CALCULATOR_H_

#include "tastylib/internal/base.h"
#include <string>
#include <iostream>
#include <vector>

TASTYLIB_NS_BEGIN


class Token {
    friend bool operator==(const Token &lhs, const Token &rhs) {
        return lhs.type_ == rhs.type_ && lhs.val_ == rhs.val_;
    }

    friend bool operator!=(const Token &lhs, const Token &rhs) {
        return !(lhs == rhs);
    }

public:
    enum Type {
        END_INPUT,
        NUMBER,
        OPERATOR
    };

public:
    static Token end() {
        return Token(Type::END_INPUT, "$");
    }

    static Token num(const std::string &v) {
        return Token(Type::NUMBER, v);
    }

    static Token oper(const std::string &v) {
        return Token(Type::OPERATOR, v);
    }

    Type type() const {
        return type_;
    }

    const std::string& val() const {
        return val_;
    }

private:
    Token(const Type t, const std::string &v)
        : type_(t), val_(v) {}

private:
    Type type_;
    std::string val_;
};


class Lexer {
public:
    Lexer(std::istream &i) : cur(' '), is(i) {}

    // Read and parser one token from input stream
    Token scan();

private:
    char cur;
    std::istream &is;
};


class Parser {
public:
    Parser(std::istream &i) : cur(Token::end()), lexer(i) {}

    /*
    Parse an infix arithmetic expression and return its postfix tokens.

    @throw std::runtime_error if parse failed
    */
    const std::vector<Token>& parse();

private:
    void read() {
        cur = lexer.scan();
    }
    
    // Recursive descent of nonterminals
    void expr();
    void A();
    void tmpA();
    void B();
    void tmpB();
    void factor();

private:
    Token cur;
    Lexer lexer;
    std::vector<Token> postfix;
};


class Calculator {
public:
    Calculator(std::istream &i) : parser(i) {}

    /*
    Return the result of an infix arithmetic expression.

    @throw std::runtime_error if the expression is invalid
    */
    long calculate();

private:
    Parser parser;
};


TASTYLIB_NS_END

#endif
