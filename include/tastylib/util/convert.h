#ifndef TASTYLIB_CONVERT_H_
#define TASTYLIB_CONVERT_H_

#include "tastylib/internal/base.h"
#include <sstream>
#include <string>
#include <iomanip>

TASTYLIB_NS_BEGIN

template<typename T>
std::string toString(const T &obj) {
    std::ostringstream oss;
    oss << std::setiosflags(std::ios::fixed) << obj;
    return oss.str();
}

TASTYLIB_NS_END

#endif