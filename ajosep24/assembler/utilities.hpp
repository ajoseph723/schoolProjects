#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_

#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

String inToPost(String &);

void assemble(String &, std::ostream &);

String evaluate(String &, String &, String &, std::ostream &, int&);

String numToString(int);

#endif