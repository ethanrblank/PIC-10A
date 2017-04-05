/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #2
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program takes user's input of seconds
 and speed in mph and calculates how far the user has travelled as
 well as for how long in years, days, hours, minutes, and seconds.
 
 List of known bugs: None.
***********************************************************************/

#include <iostream>
using namespace std;


int main () {
    // Here are all my constant variables. These variables will be used for several conversions.
    
    const int seconds_per_year=31536000;
    const int seconds_per_day=86400;
    const int seconds_per_hour=3600;
    const int seconds_per_minute=60;
    const int days_in_year=365;
    const int hours_in_day=24;
    const int minutes_in_hour=60;
    
    int seconds; // Defining variable seconds
    int speed; // Defining variable speed
    
    cout << "Please give me the time of travel in seconds. ";
    cin >> seconds;
    cout << "\nPlease give me your speed in miles per hour. ";
    cin >> speed;
    
    // After user inputs integer values for seconds and speed, we can define new variables that utilize the constant conversion
    // variables that were defined above.
    
    double distance = seconds*(double)speed/seconds_per_hour; // Defining distance by converting the speed to miles per second,
                                                              // then multiplying by seconds
    int years = seconds/seconds_per_year;                     // Calculation of years from seconds
    int days = (seconds/seconds_per_day)%days_in_year;        // Calculation of total days. Remainder is the amount of days in
                                                              // a year.
    int hours = (seconds/seconds_per_hour)%hours_in_day;      // Calculation of total hours. Remainder displays the number of
                                                              // hours in a day.
    int minutes = (seconds/seconds_per_minute)%minutes_in_hour; // Calculation of total minutes. Remainder displays the number
                                                              // of minutes in an hour.
    int display_seconds = seconds%seconds_per_minute;         // Using display_seconds rather than seconds correct formats
                                                              // the remainder input number of seconds.
    
    cout << "\nYou have been travelling for: "
        << years << " years "
        << days << " days "
        << hours << " hours "
        << minutes << " minutes and "
        << display_seconds << " seconds.\n\n";
    cout << "Your distance traveled is: " << distance << " miles.\n\n";
    
    system("pause");
    return 0;
}