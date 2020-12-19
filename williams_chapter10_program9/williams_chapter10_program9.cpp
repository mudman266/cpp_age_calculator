// Josh Williams
// 3/5/2020
// CSC - 234 - 81A
// Chapter 10 - Program 9 - Age

// Gather the user's name and year of birth. Must be entered as 18XX 19XX or 20XX. Greet the user and report their age.

// The book utilizes the seemingly depreicated locatime(timer) instead of localtime_s(const timer, buffer). The following line removes the depreciated warning.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    // Variables
    int yearBorn{};
    int age{};
    string name{};
    time_t epSeconds;
    tm* ptCalendar = nullptr;

    // Welcome Message
    cout << "Age Calculator\n\n";

    // Gather name
    cout << "Name: ";
    cin >> name;

    // Gather year of birth
    cout << "Year Born: ";
    cin >> yearBorn;

    // Verify age
    while (yearBorn < 1800 || yearBorn > 2099) {
        // Year born outside of range
        cout << "Year born (1800 - 2099): ";
        cin >> yearBorn;
    }

    // Year born in valid range. Calculate age.
    // Seoncds since epoch
    epSeconds = time(NULL);
    // Convert to calendar date
    ptCalendar = localtime(&epSeconds);
    // Calculate age
    age = 1900 + ptCalendar->tm_year - yearBorn;

    // Greeting
    cout << "\nHello " << name << ". You are " << age << " years old." << endl;
}
