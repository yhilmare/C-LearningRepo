//
// Created by Administrator on 2018/12/6.
//

#ifndef BASICKNOWLEDGE_DATE_H
#define BASICKNOWLEDGE_DATE_H

#include <iostream>
#include <iomanip>

namespace DATE{
    enum date_format{
        format_24_hours,
        format_12_hours
    };
    class Date{
    private:
        long million_seconds;
        int year;
        int month;
        int day;
        int hours;
        int minutes;
        int seconds;
        date_format format;
        bool is_leap_year(int dest_year);
    public:
        Date();
        Date(long million_seconds);
        Date(int year, int month, int day, int hours, int minutes, int seconds, date_format format = format_24_hours);
        ~Date();
        void reset_time();
        void set_date_format(date_format format);
        long get_million_seconds();
        Date operator+(const Date &date);
        Date operator-(const Date &date);
        friend std::ostream &operator<<(std::ostream &os, const Date &date){
            if (date.format == format_24_hours) {
                os << std::setfill('0') << date.year << "-"
                   << std::setw(2) << date.month << "-"
                   << std::setw(2) << date.day << " "
                   << std::setw(2) << date.hours << ":"
                   << std::setw(2) << date.minutes << ":"
                   << std::setw(2) << date.seconds;
            } else {
                os << std::setfill('0') << date.year << "-"
                   << std::setw(2) << date.month << "-"
                   << std::setw(2) << date.day << " "
                   << std::setw(2) << ((date.hours > 12) ? (date.hours - 12) : date.hours) << ":"
                   << std::setw(2) << date.minutes << ":"
                   << std::setw(2) << date.seconds << ((date.hours >= 12) ? "pm" : "am");
            }
            return os;
        }
        explicit operator long() const;//这是C++中的强制类型转换函数
    };
}
//inline std::ostream& DATE::operator<<(std::ostream &os, const DATE::Date &date) {
//    if (date.format == format_24_hours) {
//        os << std::setfill('0') << date.year << "-"
//           << std::setw(2) << date.month << "-"
//           << std::setw(2) << date.day << " "
//           << std::setw(2) << date.hours << ":"
//           << std::setw(2) << date.minutes << ":"
//           << std::setw(2) << date.seconds;
//    } else {
//        os << std::setfill('0') << date.year << "-"
//           << std::setw(2) << date.month << "-"
//           << std::setw(2) << date.day << " "
//           << std::setw(2) << ((date.hours > 12) ? (date.hours - 12) : date.hours) << ":"
//           << std::setw(2) << date.minutes << ":"
//           << std::setw(2) << date.seconds << ((date.hours >= 12) ? "pm" : "am");
//    }
//    return os;
//}



#endif //BASICKNOWLEDGE_DATE_H
