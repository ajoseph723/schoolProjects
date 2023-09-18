#ifndef BIGINT_HPP_
#define BIGINT_HPP_

#include <iostream>

const int capacity = 200;
class bigint
{

public:
    bigint();             // Default constructor
    bigint(int);          // constructor form an integer
    bigint(const char[]); // constructor for character array

    void debugPrint(std::ostream &) const;

    friend std::ostream &operator<<(std::ostream &, const bigint &);
    friend std::istream &operator>>(std::istream &, bigint &);

    friend bool operator==(const bigint &, const bigint &);

    friend bigint operator+(const bigint &, const bigint &);

    int operator[](const int &);

private:
    int num[capacity];
};

#endif