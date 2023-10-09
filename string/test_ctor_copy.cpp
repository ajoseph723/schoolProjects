// string Test Program
//
// Tests:  copy constructor
#include <iostream>
#include <cassert>
#include "string.hpp"


int main() {
    {
        //testing default string
        String a;
        String b(a);

        assert(b == "");
    }

    {
        //testing string with single character
        String a('a');
        String b(a);

        assert(b == "a");
    }

    {
        //testing string with multiple characters
        String a("abc");
        String b(a);

        assert(b == "abc");
    }

    {
        //testing midifying string after copy constructor use
        String a("abc");
        String b(a);

        assert(b == "abc");

        b += "abc";
        assert(b == "abcabc");
    }


}