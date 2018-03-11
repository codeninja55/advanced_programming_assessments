//
// Created by Ali on Dec 27 '10 at 20:10
// https://stackoverflow.com/questions/281818/unmangling-the-result-of-stdtype-infoname
//

#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <typeinfo>

std::string demangle(const char* name);

template <class T>
std::string type(const T& t) {

    return demangle(typeid(t).name());
}

#endif