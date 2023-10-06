#include "object_construction.hpp"
#include <iostream>

int main()
{
    object a;
    object b;
    a.foo(b);
    b = a;

    return 0;
}