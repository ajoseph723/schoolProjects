//
// File: stack.hpp
//
// Programmer:
// Date:       Fall 2023
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include "../string/string.hpp"

template <typename T>
class node
{
public:
    node() : next(0){};
    node(const T &item) : data(item), next(0){};
    T data;
    node<T> *next;
};

// CLASS INV:
//
template <typename T>
class stack
{
public:
    stack() : tos(0){};
    stack(const stack<T> &);
    ~stack();
    void swap(stack<T> &);
    stack<T> &operator=(stack<T> rhs)
    {
        swap(rhs);
        return *this;
    };

    bool empty() const { return tos == 0; };
    bool full() const;
    T top() const { return tos->data; };
    T pop();
    void push(const T &);

private:
    node<T> *tos;
};

template <typename T>
stack<T>::stack(const stack<T> &actual)
{
    node<T> *temp = actual.tos,
            *bottom = 0;
    tos = 0;
    while (temp != 0)
    {
        if (tos == 0)
        {
            tos = new node<T>(temp->data);
            bottom = tos;
        }
        else
        {
            bottom->next = new node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template <typename T>
stack<T>::~stack()
{
    node<T> *temp;
    while (tos != 0)
    {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
void stack<T>::swap(stack<T> &rhs)
{
    node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const
{
    node<T> *temp = new (std::nothrow) node<T>(); // Return 0 if no memory
    if (!temp)
        return true;
    delete temp;
    return false;
}

// REQUIRES: tos-> x1 -> x2 -> ...xn->0
// ENSURE:    tos-> x2 -> ...xn->0
template <typename T>
T stack<T>::pop()
{
    assert(!(empty()));
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

// REQUIRES: tos-> x1 -> x2 -> ...xn->0
// ENSURE:    tos-> item -> x1 -> x2 -> ...xn->0
template <typename T>
void stack<T>::push(const T &item)
{
    node<T> *temp = new (std::nothrow) node<T>(item);
    if (!temp)
    {
    }
    else
    {
        temp->next = tos;
        tos = temp;
    }
}

#endif
