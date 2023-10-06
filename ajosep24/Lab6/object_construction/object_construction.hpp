#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP

#include <iostream>

class object
{
public:
    object();                          // default constructor
    object(const object &);            // copy constructor
    object &operator=(const object &); // overload
    ~object();

    int foo(object); // fucntion to invoke copy constructor

private:
    int size;
    int *ptr;
};

#endif