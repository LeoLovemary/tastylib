#ifndef TASTYLIB_CONVERT_H_
#define TASTYLIB_CONVERT_H_

#include "tastylib/internal/base.h"
#include <string>

TASTYLIB_NS_BEGIN

template<typename T>
std::string toString(const T &obj) {
    return std::to_string(obj);
}

TASTYLIB_NS_END

#endif
