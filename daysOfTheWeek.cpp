#include <iostream>
using namespace std;

int calculate(int year, int month, int day, int Century[]);
void finalDay(int remainder);

int main() {
  int year, month, day, dayOfTheWeek;
  int Century20th[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
  int Century21st[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  int remainder;
  cout << "Enter the year: ";
  cin >> year;
  cout << "Enter the number of the month: ";
  cin >> month;
  cout << "Enter the day: ";
  cin >> day;

  if (year > -2001 && year <= 2100) {
    year = year - 2000;
    remainder = calculate(year, month, day, Century21st);
  } else if (year >= 1901 && year <= 2000) {
    year = year - 1900;
    remainder = calculate(year, month, day, Century20th);
  } else {
    cout << "The year you entered is not in the range of accepted values (20th "
            "and 21st century)";
  }
  finalDay(remainder);
}

int calculate(int year, int month, int day, int Century[]) {
  int sum;
  sum = year;
  year = year / 4;
  sum += year;
  sum += Century[month - 1];
  sum += day;
  sum %= 7;
  return sum;
}

void finalDay(int remainder) {
  switch (remainder) {
  case 0:
    cout << "The day for the date provided is Saturday!" << endl;
    break;
  case 1:
    cout << "The day for the date provided is Sunday!" << endl;
    break;
  case 2:
    cout << "The day for the date provided is Monday!" << endl;
    break;
  case 3:
    cout << "The day for the date provided is Tuesday!" << endl;
    break;
  case 4:
    cout << "The day for the date provided is Wednesday!" << endl;
    break;
  case 5:
    cout << "The day for the date provided is Thursday!" << endl;
    break;
  case 6:
    cout << "The day for the date provided is Friday!" << endl;
    break;
  default:
    cout << "There was an error." << endl;
    break;
  }
}
