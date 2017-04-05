/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #9
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This is the C++ file for the person class
 member functions.
 
 List of known bugs: None.
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "phonebook.hpp"



using namespace std;

Person::Person() // Default constructor
{
    name="";
    phone=0;
}

Person::Person(string new_name, int new_phone) // Constructor for programmer specific inputs Ex. Person A(Ethan, 4213412);
{
    name=new_name;
    phone=new_phone;
}

string Person::get_name() const // Returns the person's name Ex. A.get_name() = Ethan
{
    return name;
}

int Person::get_phone() const // Returns the person's phone number Ex. A.get_phone() = 4213412
{
    return phone;
}


bool Person::operator<(Person p) const // Compares the two people's names and sorts alphabetically Ex. Ethan < Alex
{
    return name < p.name;
}

void Person::print() const // Prints the name Ex. A.print() = Ethan | 4213412
{
    cout << name << " | " << phone;
}


void swap(Person &A, Person &B) // Swaps two people. Passed by reference
{
    Person temp=A;
    A=B;
    B=temp;
}

void add_people(vector<Person> &phone_book) // Function adds people to the phone_book vector
{
    string cname;
    int cnumber;
    do
    {
        cout << "Enter the contact's name (or \"Q\" to quit): ";
        getline(cin, cname);
        if (cname != "q" && cname != "Q")
        {
            cout << "Enter the contact's number: ";
            while (!(cin>>cnumber)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the contact's number: ";
            }
            string clear;
            getline(cin, clear);
            Person A(cname, cnumber);
            phone_book.push_back(A);
        }
    }
    while (cname != "q" && cname != "Q");
    
}

int find (const vector<Person> &phone_book, string name) // Finds a contact in the phone_book vector
{
    int i=0;
    while (i < phone_book.size() && phone_book[i].get_name() != name)
    {
        ++i;
    }
    if (i==phone_book.size())
    {
        cout << "The contact was not found.";
        return -12;
    }
    else
        return i;
}

void erase(vector<Person> &phone_book, string name) // Erases a contact in the phone_book vector
{
    int pos=find(phone_book, name);
    if (pos!=-12)
    {
        for (int i=pos; i<phone_book.size(); ++i)
        {
            phone_book[i]=phone_book[i+1];
        }
        phone_book.pop_back();
    }
}

void sort(vector<Person> &phone_book) // Utilizes the sort algorithim and the overloaded < operator to sort the contacts
{
    sort(phone_book.begin(), phone_book.end());
}

void shuffle(vector<Person> &phone_book) // Utilizes the swap function to shuffle the contacts
{
    int slot1, slot2;
    int size = (int)phone_book.size();
    for (int i=0; i<300; ++i)
    {
        slot1 = rand()%size;
        slot2 = rand()%size;
        swap(phone_book[slot1], phone_book[slot2]);
    }
}

void reverse(vector<Person> &phone_book) // Copies the vector and then reverses the phone_book vector
{
    vector<Person> v=phone_book;
    int j=(int)phone_book.size()-1;
    for (int i=0; i < phone_book.size(); ++i)
    {
        Person p=v[j];
        phone_book[i]=p;
        --j;
    }
}

int lookup(const vector<Person> &phone_book, string name) // Looks up a contact in the phone_book vector
{
    int i=0;
    while (i < phone_book.size() && phone_book[i].get_name() != name)
    {
        ++i;
    }
    return phone_book[i].get_phone();
}

void print(vector<Person> &phone_book) // Prints the variables in the phone_book vector to the console
{
    for (int i=0; i<phone_book.size(); ++i)
    {
        phone_book[i].print();
        cout << endl;
    }
    
}
