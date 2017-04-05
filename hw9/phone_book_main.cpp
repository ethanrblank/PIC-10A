#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "phonebook.hpp"

using namespace std;




int main()
{
    
    vector<Person> phone_book;
    string name;
    int number;
    int answer;
    
    srand((int)(time(0)));
    
    phone_book.push_back(Person("Bruin, Joe", 5556456));
    phone_book.push_back(Person("Simpson, Homer", 5557471));
    phone_book.push_back(Person("Duffman, Barry", 5533331));
    
    
    cout <<"\n";
    cout << "Your phone book contains the following names and numbers: \n";
    
    for (int i=0; i < phone_book.size(); i++)
    {
        
        phone_book[i].print();
        cout << "\n";
    }
    cout <<"\n";
    answer=0;
    
    while (answer != 8)
    {
        cout << "\nChoose from the following options:\n\n";
        
        cout << "1) Add people to the phone book.\n";
        cout << "2) Erase a person from the phone book.\n";
        cout << "3) Sort the phone book.\n";
        cout << "4) Shuffle the phone book.\n";
        cout << "5) Reverse the phone book.\n";
        cout << "6) Print the phone book.\n";
        cout << "7) Look up a person in the phone book.\n";
        cout << "8) Quit.\n\n";
        
        cin >> answer;
        
        string clear;
        
        getline(cin, clear);
        
        if (answer == 1)
            add_people(phone_book);
        else if (answer == 2)
        {
            cout << "Enter a name: ";
            getline(cin, name);
            erase(phone_book, name);
            
        }
        else if (answer == 3)
            sort(phone_book);
        else if (answer == 4)
            shuffle (phone_book);
        else if (answer == 5)
            reverse(phone_book);
        else if (answer == 6)
        {
            cout <<"\n";
            cout << "Your phone book contains the following names and numbers: \n";
            print(phone_book);
        }
        else if (answer ==7)
        {					
            cout << "Enter a name: ";
            getline(cin, name);
            int number = lookup(phone_book, name); 
            if (number > 0)
            {
                cout << "\n\nThe number for " << name << " is: " << number << "\n\n";
            }
            else
                cout << name << " not found in the phone book.\n";
        }
    }
    return 0;
}