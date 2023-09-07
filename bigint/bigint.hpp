#ifndef BIGINT_HPP_
#define BIGINT_HPP_

#include <iostream>

const int capacity = 200;
class bigint
{

public:
    bigint();
    bigint(int);
    bigint(const char[]);

    void debugPrint(std::ostream &) const;

    friend std::ostream &operator<<(std::ostream &, const bigint &);
    friend bool operator==(const bigint &, const bigint &);

    friend bigint operator+(const bigint &, const bigint &);

private:
    int num[capacity];
};

#endif