#include <iostream>
#include <memory>
#include "Date.h"

int main() {
  Date today(04, 19, 2022);
  today.formatDate();


  Date* day2 = (today - 50);
  day2->formatDate();

  ++today;
  today.formatDate();
  --today;
  today.formatDate();

}