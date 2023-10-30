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
    }
    std::cout << "Destructor ran." << std::endl;

    // ADD ADDITIONAL TESTS AS NECESSARY

    std::cout << "Done testing destructorxs." << std::endl;
    return 0;
}
