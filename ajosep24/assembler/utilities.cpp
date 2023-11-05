#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"
#include "utilities.hpp"

String inToPost(String &original)
{
    stack<String> input;
    int i = 0;
    String temp;
    String right;
    String oper;
    String left;

    while (original[i] != ';')
    {
        if (original[i] == ')')
        {
            right = input.pop();
            oper = input.pop();
            left = input.pop();
            input.push(right + oper + left);
        }
        else if (original[i] != '(' && original[i] != ' ')
            input.push(original[i]);
        ++i;
    }
    return input.pop();
}