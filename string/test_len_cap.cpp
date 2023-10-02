// bigint Test Program
//
// Tests:  length() and capacity(), uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing length()
    {
        String a('a');
        String b("ab");
        assert(a.length() == 1);
        assert(b.length() == 2);
    }

    // testing capacity()
    {
        String a("abc");

        assert(a.capacity() == (STRING_SIZE - 1));
    }

    std::cout << "Done testing length and capacity." << std::endl;
    return 0;
}