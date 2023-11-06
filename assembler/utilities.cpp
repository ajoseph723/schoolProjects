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
            input.push(left + right + oper);
        }
        else if (original[i] != '(' && original[i] != ' ')
            temp += original[i];
        else if (original[i] == ' ' && temp.length() > 0)
        {
            input.push(temp);
            temp = "";
        }
        ++i;
    }
    return input.pop();
}