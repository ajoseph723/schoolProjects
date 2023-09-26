// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3); // Will FAIL, fix and add test cases.
    }

    // Add test cases as needed.
    {
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 6);
    }

    {
        // Setup fixture
        bigint bi(12);

        // Test
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 108);
    }

    {
        // Setup fixture
        bigint bi(99);

        // Test
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 891);
    }
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
