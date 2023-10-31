//  Stack class test program
//
//  Tests: copy constructor, Uses: swap()
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
        stack<int> x;
        stack<int> y;

        // TEST
        x.swap(y);

        std::cout << "Copy constructor ran." << std::endl;
    }

    // ADD ADDITIONAL TESTS AS NECESSARY

    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}
