//  Stack class test program
//
//  Tests: push(), pop(); Uses: Stack, empty(), top();
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        // testing push and pop with single node
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        assert(x.pop() == 1);

               assert(x.empty());
    }

    {
        // testing push and pop with multiple nodes
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        x.push(2);
        assert(x.top() == 2);

        x.pop();
        assert(x.top() == 1);

        x.pop();
        assert(x.empty());
    }

    std::cout << "Done testing push and pop." << std::endl;
    return 0;
}