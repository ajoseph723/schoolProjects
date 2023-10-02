// bigint Test Program
//
// Tests:  findch(), uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing search from beginning of string
    {
        String a("abcd");

        assert(a.findch(0, 'c') == 2);
    }

    // testing in the middle of the string
    {
        String a("abacd");
        assert(a.findch(1, 'a') == 2);
    }

    // testing finding a letter at the end of string
    {
        String a("abc");
        assert(a.findch(0, 'c') == 2);
    }

    // testing String with a length of 1
    {
        String a("a");
        assert(a.findch(0, 'a') == 0);
    }

    // testing letter not found from length
    {
        String a("abc");
        assert(a.findch(1, 'a') == -1);
    }

    std::cout << "Done testing findchar." << std::endl;
    return 0;
}