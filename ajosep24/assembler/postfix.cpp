#include <iostream>
#include <fstream>
#include "utilities.hpp"
#include "stack.hpp"
#include "../string/string.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " input [output]";
        return 1;
    }

    String outFile;

    if (argc >= 3)
    {
        outFile = argv[2];
    }
    char trueOutFile[outFile.length()];

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Can not open " << argv[1] << std::endl;
        exit(2);
    }

    std::ostream *output = &std::cout; // write to screen default

    std::ofstream outputFile;
    if (outFile.length() > 0)
    {
        for (int i = 0; i < outFile.length() - 1; ++i)
            trueOutFile[i] = outFile[i];

        outputFile.open(trueOutFile);
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Can not open " << argv[2] << std::endl;
            exit(3);
        }
        output = &outputFile;
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
            String postfix = inToPost(infix);
            *output << postfix << std::endl;
            infix = "";
        }
        inputFile.get(ch);
    }

    inputFile.close();
    if (outputFile.is_open())
        outputFile.close();

    return 0;
}