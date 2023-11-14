#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"
#include "utilities.hpp"
#include <vector>

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
            temp += ' ';
            input.push(temp);
            temp = "";
        }
        ++i;
    }
    return input.pop();
}

void assemble(String &original, std::ostream &out) {
    String lhs;
    String rhs;
    int current = 0;
    stack<String> temp;
    
    String post = inToPost(original);
    std::vector<String> postVec = post.split(' ');
    
    out << "Infix: " << original << std::endl 
        << "Postfix" << post << std::endl << std::endl;

    int i = 0;

    while(postVec[i] != "") {
        if(postVec[i] != "+" && 
        postVec[i] != "-" &&
        postVec[i] != "*" &&
        postVec[i] != "/") {
            temp.push(postVec[i]);
        } else {
            rhs = temp.pop();
            lhs = temp.pop();
            temp.push(evaluate(lhs, rhs, postVec[i], out, current));
        }
        ++i;
    }
}

String evaluate(String &lhs, String &rhs, String &op, std::ostream &out, int& temp) {
    out << "  LD  " << lhs << std::endl;
    
    if(op == "+")
        out << "  AD  ";
    else if(op == "-")
        out << "  SB  ";
    else if(op == "*")
        out << "  MU  ";
    else if(op == "/")
        out << "  DV  ";
    out << rhs << std::endl;

    ++temp;
    String tempstr = "TMP" + numToString(temp);
    out << "  ST  " << tempstr << std::endl;
    return tempstr;
}

String numToString(int num) {
    String final;
    int temp;
    int i = 0;
    char ch;
    while(num >= 10){
        temp = num;
        i = 0;
        while(temp >= 10) {
            temp = temp / 10;
            ++i;
        }
        ch = temp - '0';
        final += ch;
        num = num - (temp * 10^i);
    }
    return final;
}