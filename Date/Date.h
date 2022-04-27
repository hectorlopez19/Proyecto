#pragma once 
#include <iostream>

class Date {
  private:
    int day, month, year;

  public:
    Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {};

    bool leapYear() {
      return (year % 4 == 0 && year % 100 == 0 && year % 400 == 0);
    }

    int daysInMonth() {
      int monthDays = 31;
      if(month == 4 || month == 6 || month == 9 || month == 11) {
        monthDays--;
      }
      if(month == 2) {
        if(leapYear()) {
          monthDays = 29;
        }
        else {
          monthDays = 28;
        }
      }
      return monthDays;
    }

    void formatDate() {
      if(month < 10) {
        std::cout << 0;
      }
      std::cout << month << "/";
      if(day < 10) {
        std::cout << 0;
      }
      std::cout << day << "/";
      if(year < 0) {
        std::cout << year * -1 << " a.e.c\n";
      }
      else {
        std::cout << year << std::endl;
      }
    }

    Date* operator +(int days) {
      Date* newDate = new Date(month, day, year);
      while(newDate->day + days > newDate->daysInMonth()) {
        days -= (newDate->daysInMonth() - newDate->day);
        newDate->addMonth(1);
        newDate->day = 0;
      }
      newDate->day += days;
      return newDate;
    }

    Date* operator -(int days) {
      Date* newDate = new Date(month, day, year);
      while(newDate->day - days < 1) { 
        days -= newDate->day;
        newDate->subtractMonth(1);
        newDate->day = newDate->daysInMonth();
      }
      newDate->day -= days;
      return newDate;
    }

    void addMonth(int months) {
      while(month + months > 12) {
        months -= 12 - month;
        addYear(1);
        month = 0;
      }
      month += months;
    }

    void subtractMonth(int months) {
      while(month - months < 1) {
        months -= month;
        substractYear(1);
        month = 12;
      }
      month -= months;
    }

    void addYear(int years) {
      year += years;
    }

    void substractYear(int years) {
      if(year - years > 0) {
        year -= years;
      }
      else {
        year -= years + 1;
      }
    }

    //Prefix
    Date& operator ++() {
      ++day;
      return *this;
    }
    Date& operator --() {
      --day;
      return *this;
    }

    //postfix
    Date operator ++(int) {
      Date copy(month, day, year);
      ++day;
      return copy;
    }
    Date operator --(int) {
      Date copy(month, day, year);
      --day;
      return copy;
    }
 
};