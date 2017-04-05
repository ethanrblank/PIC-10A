#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include <vector>
using namespace std;

class Person
{
public:
    Person();
    Person(string new_name, int new_phone);
    string get_name() const;
    int get_phone() const;
    bool operator < (Person p) const;
    void print() const;
    
private:
    string name;
    int phone;
};

void swap(Person &A, Person &B);
void add_people(vector<Person> &phone_book);
void erase(vector<Person> &phone_book, string name);
void sort(vector<Person> &phone_book);
void shuffle(vector<Person> &phone_book);
void reverse(vector<Person> &phone_book);
void print(vector<Person> &phone_book);
int lookup(const vector<Person> &phone_book, string name);
#endif
