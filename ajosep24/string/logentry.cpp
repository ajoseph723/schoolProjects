//
//
// File:        logentry.cpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//

#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

void Date::setYear(String s)
{
    int temp = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        temp = temp + (s[i] - '0');
        temp = temp * 10;
    }
    temp = temp / 10;
    year = temp;
}

Time::Time(String hr, String min, String sec)
{
    int temp = 0;
    for (int i = 0; i < hr.length(); ++i)
    {
        temp = temp + (hr[i] - '0');
        temp = temp * 10;
    }
    temp = temp / 10;
    hour = temp;
    temp = 0;

    for (int i = 0; i < min.length(); ++i)
    {
        temp = temp + (min[i] - '0');
        temp = temp * 10;
    }
    temp = temp / 10;
    minute = temp;
    temp = 0;

    for (int i = 0; i < sec.length(); ++i)
    {
        temp = temp + (sec[i] - '0');
        temp = temp * 10;
    }
    temp = temp / 10;
    second = temp;
}

// REQUIRES:
// ENSURES:
//
LogEntry::LogEntry(String s)
{
    // making the string into a vector of strings
    std::vector<String> vec = s.split(' ');

    // checking to see if the input is a valid logentry
    if (vec.size() != 10)
    {
        *this = LogEntry();
    }
    else
    {
        host = vec[0];

        // setting the Date
        Date tempDate;
        std::vector<String> dateVec = vec[3].split('/');
        std::vector<String> dayVec = dateVec[0].split('[');

        date.setDay(dayVec[1]);
        date.setMonth(dateVec[2]);

        std::vector<String> yearVec = dateVec[2].split(':');

        date.setYear(yearVec[0]);

        // setting the time
        Time tempTime(yearVec[1], yearVec[2], yearVec[3]);
        time = tempTime;

        // getting request
        std::vector<String> requestVec = s.split('"');
        request = requestVec[1];

        // setting status
        status = vec[8];

        // setting number_of_bytes
        String bytes = vec[9];
        for (int i = 0; i < bytes.length(); ++i)
        {
            number_of_bytes = number_of_bytes + (bytes[i] - '0');
            number_of_bytes = number_of_bytes * 10;
        }
        number_of_bytes = number_of_bytes / 10;
    }
}

// REQUIRES:
// ENSURES:
//
std::vector<LogEntry> parse(std::istream &in)
{
    std::vector<LogEntry> result;

        return result;
}

// REQUIRES:
// ENSURES:
//
void output_all(std::ostream &out, const std::vector<LogEntry> &)
{
}

// REQUIRES:
// ENSURES:
//
void by_host(std::ostream &out, const std::vector<LogEntry> &)
{
}

/// REQUIRES:
// ENSURES:
//
int byte_count(const std::vector<LogEntry> &)
{

    return 0;
}
