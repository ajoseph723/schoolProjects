// bigint Test Program
//
// Tests:  += and +, uses ==
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // testing strings of the same size
    {
        // Test
        String a("abc");
        String b("abc");
        String c;
        c = a + b;
        std::cout << c;
        // Verify
        assert(c == "abcabc");
    }

    // testing strings of different size
    {
        // Test
        String a("abc");
        String b("abcd");
        String c;
        String d;
        c = a + b;
        d = b + a;

        // Verify
        assert(c == "abcabcd");
        assert(d == "abcdabc");
    }

    // testing String + char[]
    {
        // Test
        String a("abc");
        String c;
        c = a + "abc";

        // Verify
        assert(c == "abcabc");
    }

    // testing String a = a + b
    {
        // Test
        String a("abc");
        String b("abc");
        a = a + b;

        // Verify
        assert(a == "abcabc");
    }

    // testing +=
    // testing String += String and self += self
    {
        String a("abc");
        String b("abc");
        a += b;
        assert(a == "abcabc");

        a = "abc";
        a += a;
        assert(a == "abcabc");
    }

    // testing String += char[]
    {
        // Test
        String a("abc");
        a += "abc";

        // Verify
        assert(a == "abcabc");
    }

    std::cout << "Done testing concatations." << std::endl;
    return 0;
}