#include "string.hpp"
#include <iostream>
#include <cassert>

String::String()
{
    str[0] = 0;
}

String::String(char ch)
{
    str[0] = ch;
    str[1] = 0;
}

String::String(const char s[])
{
    int i = 0;
    while (s[i] != 0)
    {
        if (i >= STRING_SIZE - 1)
            break;
        str[i] = s[i];
        ++i;
    }
    str[i] = 0;
}

int String::capacity() const
{
    return STRING_SIZE - 1;
}

int String::length() const
{
    int i = 0;
    while (str[i] != 0)
        ++i;
    return i;
}

// REQUIRES: 0 <= i < length ()
char &String::operator[](int i)
{
    assert(1 >= 0);
    assert(i < length());
    return str[i];
}

// REQUIRES: 0 <= i < length ()
char String::operator[](int i) const
{
    assert(1 >= 0);
    assert(i < length());
    return str[i];
}

String &String::operator+=(const String &rhs)
{
    int offset = 0;
    int rhsLen = rhs.length();
    int i = 0;
    while (i < rhsLen)
    {
        str[offset + i] = rhs.str[i];
        ++i;
    }
    return *this;
}

String operator+(String lhs, const String &rhs)
{
    return lhs += rhs;
}

bool String::operator==(const String &rhs) const
{
    int i = 0;
    while (str[i] != 0 && str[i] == rhs.str[i])
        ++i;
    return str[i] == rhs.str[i];
}

bool String::operator<(const String &rhs) const
{
    int i = 0;
    while ((str[i] != 0 && rhs.str[i] != 0) && (str[i] == rhs.str[i]))
        ++i;
    return str[i] < rhs.str[i];
}

bool operator==(char lhs[], const String &rhs) { return String(lhs) == rhs; }
bool operator==(char lhs, const String &rhs) { return String(lhs) == rhs; }

bool operator<(char lhs[], const String &rhs) { return String(lhs) < rhs; }
bool operator<(char lhs, const String &rhs) { return String(lhs) < rhs; }

bool operator!=(const String &lhs, const String &rhs) { return !(lhs == rhs); }
bool operator>(const String &lhs, const String &rhs) { return lhs > rhs; }

bool operator<=(const String &lhs, const String &rhs) { return !(lhs > rhs); }
bool operator>=(const String &lhs, const String &rhs) { return !(lhs < rhs); }

String String::substr(int start, int end) const
{
    String result;
    if (start < 0)
        start = 0;
    if (end >= length())
        end = length() - 1;
    if (start > end)
        return String();

    for (int i = start; i <= end; ++i)
    {
        result.str[start - i] = str[i];
    }
    return result;
}