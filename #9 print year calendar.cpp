// #9 print year calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

bool is_leap_year(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short number_of_days_in_a_month(short Month, short Year) {
    if (Month < 1 || Month > 12) {
        return 0;
    }

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (is_leap_year(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

int calculate_day_of_year(short day, short month, short year)
{
    int a = ((14 - month) / 12);
    int y = year - a;
    int m = month + (12 * a) - 2;

    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((y * m) / 12)) % 7;

    return d;
}

short read_month() {
    short Month;
    cout << "\nPlease enter a Month to check: ";
    cin >> Month;
    return Month;
}

short read_year() {
    short Year;
    cout << "\nPlease enter a Year to check: ";
    cin >> Year;
    return Year;
}

string print_months(short month, short year)
{
    string arrmonth[] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    if (month >= 1 && month <= 12)
    {
        return arrmonth[month];
    }
    else
    {
        return "";
    }
}

void print_calendar(short year) {

    cout << "_____________________________________________________\n";
    cout << "                  Calendar of: " << year << "         \n";
    cout << "_____________________________________________________\n\n";

    for (short month = 1; month <= 12; month++)
    {
        int start_day = calculate_day_of_year(1, month, year);
        short total_days_in_month = number_of_days_in_a_month(month, year);

        cout << "__________________" << print_months(month, year) << "__________________\n\n";
        cout << " Sun   Mon   Tue   Wed   Thu   Fri   Sat  \n";

        for (int j = 0; j < start_day; j++) {
            cout << "      ";
        }

        int counter = start_day;

        for (int day = 1; day <= total_days_in_month; day++) {
            cout << setw(4) << day << "  ";
            counter++;

            if (counter == 7) {
                cout << "\n";
                counter = 0;
            }
        }

        cout << "\n\n";
    }
}


int main() {

    short year = read_year();

    cout << "\n";

    print_calendar(year);

    return 0;
}
