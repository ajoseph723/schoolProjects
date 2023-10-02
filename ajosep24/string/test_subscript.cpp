// bigint Test Program
//
// Tests:  [], uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing beginning of string
    {
        String a('a');
        String b("ab");
        assert(a[0] == 'a');
        assert(b[0] == 'a');
    }

    // testing middle and end of string
    {
        String a("abc");

        assert(a[1] == 'b');
        assert(a[2] == 'c');
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}