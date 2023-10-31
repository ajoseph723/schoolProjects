//  Stack class test program
//
//  Tests: stack(), Uses: empty()
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> x;

        // VERIFY
        assert(x.empty());
    }

    // ADD ADDITIONAL TESTS AS NECESSARY

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}