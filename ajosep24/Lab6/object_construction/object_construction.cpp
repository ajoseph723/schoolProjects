#include "object_construction.hpp"
#include <iostream>

object::object()
{
    size = 10;
    ptr = new int[size];
    std::cout << "Called default constructor." << std::endl;
}

object::object(const object &actual)
{
    size = actual.size;
    ptr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = actual.ptr[i];
    }
    std::cout << "Called copy constructor." << std::endl;
}

object &object::operator=(const object &rhs)
{
    if (ptr == rhs.ptr)
        return *this;

    delete[] ptr; // epmpty lhs
    size = rhs.size;
    ptr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = rhs.ptr[i];
    }
    std::cout << "Called assignment." << std::endl;
    return *this;
}

object::~object()
{
    delete[] ptr;
    std::cout << "Called destructor." << std::endl;
}

int object::foo(object x)
{
    ptr[0] = 1;
    x.ptr[0] += ptr[0];
    return ptr[0];
}