#include "bigint.hpp"
#include <iostream>

bigint::bigint()
{
    for (int i = 0; i < capacity; ++i)
        num[i] = 0;
}

bigint::bigint(int value)
{
    for (int i = 0; i < capacity; ++i)
        num[i] = 0;

    int pos = capacity - 1;

    while (value > 0 && pos >= 0)
    {
        num[pos] = value % 10;
        value /= 10;
        --pos;
    }
}

bigint::bigint(const char value[])
{
    for (int i = 0; i < capacity; ++i)
        num[i] = 0;

    int len = 0;

    while (value[len] != 0)
        ++len;

    int index = capacity - len;

    for (int i = 0; i < len; ++i)
    {
        num[index + i] = value[i] - '0';
    }
}

void bigint::debugPrint(std::ostream &) const
{

    for (int i = 0; i < capacity; ++i)
    {
        std::cout << num[i];

        if (i != capacity)
            std::cout << "|";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const bigint &obj)
{
    int lastNum = 0;
    bool found = false;
    while (found == false && lastNum < capacity)
    {
        if (obj.num[lastNum] != 0)
            found = true;
        else
            ++lastNum;
    }

    if (lastNum == capacity)
        stream << obj.num[capacity - 1];
    else
    {
        int i = lastNum;
        int digits = 0;
        while (i < capacity)
        {

            stream << obj.num[i];
            ++i;
            ++digits;
            if (digits % 80 == 0)
                stream << std::endl;
        }
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, bigint &obj)
{
    // makes a character array the size of bigint + room for a ;
    char a[capacity + 1];
    stream >> a;
    int i = 0;
    // finds the ; within the character array and sets it equal to 0
    while (a[i] != ';')
        ++i;
    a[i] = 0;
    obj = a;
    return stream;
}

bool operator==(const bigint &lhs, const bigint &rhs)
{
    for (int i = 0; i < capacity; ++i)
    {
        if (lhs.num[i] != rhs.num[i])
        {
            return false;
        }
    }

    return true;
}

bigint operator+(const bigint &lhs, const bigint &rhs)
{
    int currentDigit = 0;
    bigint result;

    for (int i = capacity - 1; i >= 0; --i)
    {
        if ((currentDigit / 10) > 0)
            currentDigit = (currentDigit / 10);
        else
            currentDigit = 0;

        currentDigit = currentDigit + lhs.num[i] + rhs.num[i];
        result.num[i] = result.num[i] + (currentDigit % 10);
    }
    return result;
}

int bigint::operator[](const int &digit) const
{
    // figuring out where the number begins in the array
    int lastNum = 0;
    bool found = false;
    while (found == false && lastNum < capacity)
    {
        if (num[lastNum] != 0)
            found = true;
        else
            ++lastNum;
    }
    // return -1 if the number inputted isn't in the array
    if ((capacity - digit) < lastNum)
        return -1;
    else
        return num[capacity - (digit + 1)];
}

bigint bigint::timesDigit(int rhs) const
{
    int currentDigit = 0;
    bigint result;

    for (int i = capacity - 1; i >= 0; --i)
    {
        if ((currentDigit / 10) > 0)
            currentDigit = (currentDigit / 10);
        else
            currentDigit = 0;

        currentDigit = (num[i] * rhs) + currentDigit;
        result.num[i] = result.num[i] + (currentDigit % 10);
    }
    return result;
}

// REQUIRES: rhs >=0
bigint bigint::times10(int x) const
{
    bigint result;
    if (x < 0)
        return -1;

    // shifts all indexes over x places
    for (int i = x; i < capacity; ++i)
        result.num[i - x] = num[i];

    return result;
}

bigint operator*(const bigint &lhs, const bigint &rhs)
{
    int maxDigits = 0;
    int lastNum = 0;
    while (lhs.num[lastNum] == 0 && rhs.num[lastNum] == 0)
        ++lastNum;

    maxDigits = capacity - lastNum;

    bigint A;
    bigint B;
    if (lhs.num[lastNum] == 0)
    {
        B = lhs;
        A = rhs;
        while (lhs.num[lastNum] == 0)
        {
            ++lastNum;
        }
        maxDigits = capacity - lastNum + 1;
    }
    else
    {
        A = lhs;
        B = rhs;
        while (rhs.num[lastNum] == 0)
        {
            ++lastNum;
        }
        maxDigits = capacity - lastNum + 1;
    }

    bigint product = 0;
    bigint temp;
    for (int i = 0; i < maxDigits - 1; ++i)
    {
        temp = A.timesDigit(B[i]);
        product = product + temp.times10(i);
    }
    return product;
}