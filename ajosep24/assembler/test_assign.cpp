//  Stack class test program
//
//  Tests: operator =; Uses: Stack, empty(), top(), push();
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        // testing equal with single node
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        stack<int> y = x;

        assert(y.top() == 1);
        assert(x.top() == 1);

        y.pop();
        x.pop();
        assert(y.empty());
        assert(x.empty());
    }

    {
        // testing = with multiple nodes
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        x.push(2);

        stack<int> y = x;
        assert(y.top() == 2);
        assert(x.top() == 2);

        y.pop();
        x.pop();
        assert(y.top() == 1);
        assert(x.top() == 1);

        y.pop();
        x.pop();
        assert(y.empty());
        assert(x.empty());
    }

    {
        // testing = with nodes in both stacks
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        x.push(2);

        stack<int> y;
        y.push(3);
        y = x;
        assert(y.top() == 2);
        assert(x.top() == 2);

        y.pop();
        x.pop();
        assert(y.top() == 1);
        assert(x.top() == 1);

        y.pop();
        x.pop();
        assert(y.empty());
        assert(x.empty());
    }

    {
        // testing = with more nodes in lhs then rhs
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        x.push(1);
        x.push(2);

        stack<int> y;
        y.push(3);
        y.push(2);
        y.push(1);
        y = x;
        assert(y.top() == 2);
        assert(x.top() == 2);

        y.pop();
        x.pop();
        assert(y.top() == 1);
        assert(x.top() == 1);

        y.pop();
        x.pop();
        assert(y.empty());
        assert(x.empty());
    }

    {
        // testing equal with default stack
        //  SETUP FIXTURE

        // TEST
        stack<int> x;
        stack<int> y = x;

        assert(y.empty());
        assert(x.empty());
    }

    std::cout << "Done testing assign." << std::endl;
    return 0;
}