//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//

#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

class Date
{
public:
    Date(){};
    void setDay(String s) { day = s; };
    void setMonth(String s) { month = s; };
    void setYear(String);

private:
    String day, month;
    int year;
};

class Time
{
public:
    Time(){};
    void setTime(String, String, String);

private:
    int hour, minute, second;
};

class LogEntry
{
public:
    LogEntry(){};
    LogEntry(String);
    friend std::ostream &operator<<(std::ostream &, const LogEntry &);
    int getBytes() const;
    friend void output_all(std::ostream &, const std::vector<LogEntry> &);
    friend void by_host(std::ostream &, const std::vector<LogEntry> &);

private:
    String host;
    Date date;
    Time time;
    String request;
    String status;
    int number_of_bytes;
    String original;
};

//
// Free functions
//

std::vector<LogEntry> parse(std::istream &);

int byte_count(const std::vector<LogEntry> &);

#endif
