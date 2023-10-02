// bigint Test Program
//
// Tests:  substr(), uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing the entire string for substring
    {
        String a("abc");
        String b;
        b = a.substr(0, 2);

        assert(b == "abc");
    }

    // testing in the middle of the string
    {
        String a("abcdefg");
        String b;
        b = a.substr(1, 5);

        assert(b == "bcdef");
    }

    // testing start and end being the same place
    {
        String a("abc");
        String b;
        b = a.substr(1, 1);
        assert(b == "b");
    }

    std::cout << "Done testing substring." << std::endl;
    return 0;
}