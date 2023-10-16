// String Test Program
//
// Tests:  split(), uses: String
#include <iostream>
#include <cassert>
#include "string.hpp"
#include <vector>

int main()
{
    // testing split with " "
    {
        // testing 1 space in string
        {
            String a("a a");
            String b("aa aa");
            std::vector<String> vec;
            vec = a.split(' ');
            assert(vec[0] == "a");
            assert(vec[1] == "a");

            vec = b.split(' ');
            assert(vec[0] == "aa");
            assert(vec[1] == "aa");
        }

        // testing multiple spaces inside the string
        {
            String a("ab cd ef");
            String b("a b cd e");
            std::vector<String> vec;
            vec = a.split(' ');
            assert(vec[0] == "ab");
            assert(vec[1] == "cd");
            assert(vec[2] == "ef");

            vec = b.split(' ');
            assert(vec[0] == "a");
            assert(vec[1] == "b");
            assert(vec[2] == "cd");
            assert(vec[3] == "e");
        }

        // testing spaces at the beginning and end of string
        {
            String a(" a ");
            String b(" ab c ");
            std::vector<String> vec;
            vec = a.split(' ');
            assert(vec[0] == "");
            assert(vec[1] == "a");
            assert(vec[2] == "");

            vec = b.split(' ');
            assert(vec[0] == "");
            assert(vec[1] == "ab");
            assert(vec[2] == "c");
            assert(vec[3] == "");
        }
    }

    // testing inputting '-' into split
    {
        // testing single character
        {
            String a("-a-");
            String b("-a--a-");
            std::vector<String> vec;
            vec = a.split('-');
            assert(vec[0] == "");
            assert(vec[1] == "a");
            assert(vec[2] == "");

            vec = b.split('-');
            assert(vec[0] == "");
            assert(vec[1] == "a");
            assert(vec[2] == "");
            assert(vec[3] == "a");
            assert(vec[4] == "");
        }

        // testing multiple characters
        {
            String a("-ab-");
            String b("-ab--ba-");
            std::vector<String> vec;
            vec = a.split('-');
            assert(vec[0] == "");
            assert(vec[1] == "ab");
            assert(vec[2] == "");

            vec = b.split('-');
            assert(vec[0] == "");
            assert(vec[1] == "ab");
            assert(vec[2] == "");
            assert(vec[3] == "ba");
            assert(vec[4] == "");
        }

        // testing no characters
        {
            String a("--");
            std::vector<String> vec;
            vec = a.split('-');
            assert(vec[0] == "");
            assert(vec[1] == "");
            assert(vec[2] == "");
        }
    }
    std::cout << "Done testing split." << std::endl;
}