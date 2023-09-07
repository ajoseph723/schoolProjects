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