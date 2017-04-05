/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #2
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program allows the user to input two numbers and two categories.
 The program then computes and compares the ratios of either category and displays its comput-
 ations in a chart.
 
 List of known bugs: None.
 ***********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
    
    // Declaring variables used for the first two categories and their corresponding numbers.
    // We will allow the user to assign the values to these variables and then manipulate the values later
    cout << "How many in the first category? ";
    int number1;
    string category1;
    cin >> number1 >> category1;
    
    
    int number2;
    string category2;
    cout << "How many in the second category? ";
    cin >> number2 >> category2;
    cout << endl;
    
    // Calculate the lenght of the string, then subtract 1 because a string starts at 0
    int where_da_s1=(int)category1.length()-1;
    int where_da_s2=(int)category2.length()-1;

    // Utilize the calculated number to delete the "s" off the nouns, making them singular
    category1=category1.erase(where_da_s1,where_da_s1);
    category2=category2.erase(where_da_s2,where_da_s2);
    
    // Create a string that will be used to label the ratio columns utilizing new, singular values for the categories.
    string rtio1=category1 + "-to-" + category2 + " ratio";
    string rtio2=category2 + "-to-" + category1 + " ratio";
    
    // Need to add the "s" back to make the nouns plural. Used when we cout the user's input
    category1=category1 + "s";
    category2=category2 + "s";
    
    // Calculate the ratios and make them doubles
    double ratio1=(double)number1/number2;
    double ratio2=(double)number2/number1;
    
    // Set the width for the first column... the second column will just be a width of 10
    int column=(int)rtio1.length();
    
    // couts all the computed values and variables into an organized table
    //cout << setw(column+2)<< "Categories" << setw(10) << "Numbers" << endl; // <--- Uncommment this if you want headers.
    cout << setw(column) << category1 << setw(10) << number1 << endl;
    cout << setw(column) << category2 << setw(10) << number2 << endl;
    cout << setw(column) << rtio1 << setw(10) << fixed << setprecision(2) << ratio1 << endl;
    cout << setw(column) << rtio2 << setw(10) << fixed << setprecision (2) << ratio2 << endl;
    
    cout << endl;
   
    system("pause");
    return 0;
}
