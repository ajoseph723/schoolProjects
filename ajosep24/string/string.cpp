#include "string.hpp"
#include <iostream>
#include <cassert>

String::String()
{
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
}

String::String(char ch)
{

    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = 0;
}

String::String(const char s[])
{
    while (s[stringSize] != 0)
    {
        ++stringSize;
    }
    ++stringSize;

    str = new char[stringSize];
    for (int i = 0; i < stringSize - 1; ++i)
        str[i] = s[i];
    str[stringSize - 1] = 0;
}

String::String(const String &actual)
{
    stringSize = actual.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; ++i)
    {
        str[i] = actual.str[i];
    }
}

String::~String()
{
    delete[] str;
}

void String::swap(String &rhs)
{
    char *temp = str;
    str = rhs.str;
    rhs.str = temp;
    int tstringSize = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = tstringSize;
}

String &String::operator=(String rhs)
{
    swap(rhs);
    return *this;
}

int String::capacity() const
{
    return stringSize - 1;
}

int String::length() const
{
    return stringSize - 1;
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
    int offset = length();
    int rhsLen = rhs.length();
    stringSize += rhs.stringSize - 1;
    char temp[stringSize];
    int i = 0;
    while (i < length())
    {
        temp[i] = str[i];
        ++i;
    }
    i = 0;
    while (i < rhsLen)
    {
        temp[offset + i] = rhs.str[i];
        ++i;
    }
    temp[stringSize - 1] = 0;
    str = temp;
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
        result += str[i];
    }

    return result;
}

std::istream &operator>>(std::istream &stream, String &obj)
{
    // makes a character array the size of STRING_SIZE - 1
    char a[200];
    stream >> a;
    obj = a;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const String &obj)
{
    int i = 0;
    while (obj.str[i] != 0)
    {
        stream << obj.str[i];
        ++i;
    }
    return stream;
}

int String::findch(int start, char obj) const
{
    for (int i = start; i < length(); ++i)
        if (str[i] == obj)
            return i;
    return -1;
}

int String::findstr(int start, const String &obj) const
{
    int objLen = obj.length();
    int i = start;
    String temp;
    while (findch(i, obj[0]) != -1)
    {
        for (int j = 0; j < objLen; ++j)
        {
            if (str[j + findch(i, obj[0])] != 0)
            {
                temp += str[j + findch(i, obj[0])];
            }
        }
        if (temp == obj)
            return findch(i, obj[0]);
        temp = "";
        i = findch(i, obj[0]) + 1;
    }
    return -1;
}
