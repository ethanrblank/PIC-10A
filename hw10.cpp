/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #9
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program builds two matrices of a user
 specified size from either a file or a random number and then adds them.
 It outputs the results either to the console or a user-specified file.
 
 List of known bugs: None.
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int table_row = 10; // The arrays parameters are const ints of both 10
const int table_column = 10;

void check_response(int &n) // Checks a 1 or 2 response. If user does not give a good response, it outputs an error.
{
    if (n != 1 && n != 2)
    {
        do
        {
            cout << "Error: Invalid response. Please enter either 1 or 2. ";
            cin >> n;
        } while (n != 1 && n != 2);
    }
}

void check_array_response(int &n, int upperbound, int lowerbound) // Checks the user's array values to ensure they are proper.
{
    if (n < lowerbound || upperbound < n)
    {
        do
        {
            cout << "Please enter a value [1,10]. ";
            cin >> n;
        } while (n < lowerbound || upperbound < n);
    }
}

void fill_random(int array[][table_column], int row_size, int column_size) // Fills an array with random values from [-10,10]
{
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < column_size; ++j)
        {
            int value = (-10) + rand()%(10-(-10)+1);
            array[i][j]= value;
        }
    }
}

void fill_from_file(int array[][table_column], int row_size, int col_size, ifstream &fin) // Fills the array from a file.
{
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            int number;
            fin >> number;
            array[i][j] = number;
        }
    }
}

void output_to_console(int array[][table_column], int row_size, int col_size) // Outputs the array to the console.
{
    for (int i=0; i < row_size; ++i)
    {
        for (int j=0; j < col_size; ++j)
        {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }
}

void output_to_file(int array[][table_column], int row_size, int col_size, ofstream &fout) // Outputs the array to a file.
{
    for (int i=0; i<row_size; ++i)
    {
        for (int j=0; j<col_size; ++j)
        {
            fout << setw(5) << array[i][j];
        }
        fout << endl;
    }
}

void add_matrices(int ar1[][table_column], int ar2[][table_column], int add[][table_column], int row_size, int col_size) //Adds the matrices
{
    for (int i=0; i<row_size; ++i)
    {
        for (int j=0; j<col_size; ++j)
        {
            int value;
            value = ar1[i][j] + ar2[i][j];
            add[i][j] = value;
        }
    }
}


int main() {
    srand((int)time(0));
    ifstream fin; // Declaration of fstream variables
    ofstream fout;
    
    // Declaration of matrices
    int table[table_row][table_column];
    int table2[table_row][table_column];
    int add[table_row][table_column];
    int row, column;
    cout << "How many rows do you want in your matrix? ";
    cin >> row;
    check_array_response(row, 10, 1); // Checks to make sure the answers are valid
    cout << "How many columns do you want in your matrix? ";
    cin >> column;
    check_array_response(column, 10, 1); // Check to make sure answers are valid.
    int response;
    cout << "Should the input be from:\n1. From a file\n2. Random values" << endl;
    cin >> response;
    check_response(response);
    if (response == 1) // All for from a file.
    {
        cout << "Please enter the file name. ";
        string filename;
        cin >> filename;
        fin.open(filename.c_str());
        fill_from_file(table, row, column, fin); // Reads values from the file
        fill_from_file(table2, row, column, fin); // Reads values from the file
        fin.close();
    }
    else // response = 2
    {
        fill_random(table, row, column); // Fills values from random numbers
        fill_random(table2, row, column); // Fills values from random numbers
    }
    add_matrices(table, table2, add, row, column); // adds the matrices together
    cout << "Should the output go to:\n1. A file\n2. The console" << endl;
    int response2;
    cin >> response2;
    check_response(response2); // Checks the response
    if (response2 == 1)
    {
        cout << "Please enter the output file name. ";
        string outfile;
        cin >> outfile;
        fout.open(outfile.c_str());
        output_to_file(table, row, column, fout); // Outputs to file
        fout << "\n\n";
        output_to_file(table2, row, column, fout); // Outputs to file
        fout << "\n\n";
        output_to_file(add, row, column, fout); // Outputs to file
        fout.close();
    }
    else // Outputs to console
    {
        output_to_console(table, row, column);
        cout << "\n\n";
        output_to_console(table2, row, column);
        cout << "\n\n";
        output_to_console(add, row, column);
    }

    system("pause");
    return 0;
}