// bigint Test Program
//
// Tests:  findstr(), uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing finding one letter
    {
        String a("abcdefg");
        String b('a');

        assert(a.findstr(0, b) == 0);
    }

    // testing finding multiple letters
    {
        String a("abcdefg");
        String b("abc");

        assert(a.findstr(0, b) == 0);
    }

    // testing finding from middle of string
    {
        String a("abbabb");
        String b("abb");

        assert(a.findstr(1, b) == 3);
    }

    // testing not almost found string and string not found
    {
        String a("abbabbc");
        String b("abbc");
        String c("d");

        assert(a.findstr(0, b) == 3);
        assert(a.findstr(0, c) == -1);
    }

    std::cout << "Done testing findstring." << std::endl;
    return 0;
}