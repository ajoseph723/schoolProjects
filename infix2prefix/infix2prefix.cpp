#include <iostream>
#include "../assembler/stack.hpp"
#include "../string/string.hpp"
#include <fstream>

String inToPre(String &original);

int main() {
    std::ifstream inputFile("data3-1.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Can not open file" << std::endl;
        exit(1);
    }

    String infix;
    char ch;
    inputFile.get(ch);
    while (!inputFile.eof())
    {
        if (ch != '\n')
        {
            infix += ch;
        }
        else
        {
            String postfix = inToPre(infix);
            std::cout << postfix << std::endl;
            infix = "";
        }
        inputFile.get(ch);
    }

    inputFile.close();

    return 0;
}




String inToPre(String &original)
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
            input.push(oper +left + right);
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