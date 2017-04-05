/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #8
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program generates vectors, compares them
 and creates new vectors based on their comparisons. It also includes a
 class called Fractions and creates a vector of fraction objects and
 compares its elements.
 
 List of known bugs: None.
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Fraction { // Here I have written my class declaration for my Fraction class. With all my functions and constructors.
public:
    Fraction();
    Fraction(int newNumerator, int newDenominator);
    int get_numerator() const;
    int get_denominator() const;
    bool operator < (Fraction f) const; // overloaded bool operator to compare fractions.
    
private:
    int numerator;
    int denominator;
};

Fraction::Fraction() { // default constructor.
    numerator=0;
    denominator=0;
}

Fraction::Fraction(int newNumerator, int newDenominator){ // user inputed constructor
    numerator=newNumerator;
    denominator=newDenominator;
}

int Fraction::get_numerator() const { // returns the numerator
    return numerator;
}

int Fraction::get_denominator() const { // returns the denominator
    return denominator;
}

bool Fraction:: operator<(Fraction f) const {
    return ((double)numerator/denominator) < ((double)f.numerator/f.denominator); // compares fractions by their decimal values
}

// end of class

/***********************************************************************************************/

// Functions

void output(const vector<int> &v){ // this loops through the size of a vector if ints and outputs it
    for (int i=0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

void fill_fraction(vector <Fraction> &v){ // this fills a vector of fractions to 100 spaces
    for (int i=0; i<100; ++i)
    {
        Fraction A(rand()%(100-(-100)+1), rand()%(100-1+1)+1);
        v[i]=A;
    }
}

double max_fraction(const vector <Fraction> &v){ // this determines the greatest Fraction in the vector
    Fraction m = v[0];
    for (int i=1; i<v.size(); ++i) // cylces through the fraction vector.
        {
            if (m < v[i]) // if the proceeding fraction is larger, ti will assign m to the larger fraction.
                m = v[i];
        }
    double decimal = (double)m.get_numerator()/(double)m.get_denominator();
    return decimal; // and then returns the decimal value
}

void fill_vector(vector<int> &v){ // fills a vector of ints with random numbers from [-10,10]
    for (int i=0; i < v.size(); ++i){
        v[i]=rand()%(10-(-10)+1)-10;
    }
}

int frequency(const vector<int> &v, int value){ // calculates the frequence of a specific int within a vector
    int i=0;
    int freq=0;
    while (i<v.size()){
        if (v[i]==value)
            ++freq;
        ++i;
    }
    return freq;
}

vector<int> common_elements(const vector<int> &v1, const vector<int> &v2){
    vector <int> common;
    for(int i=0; i<v1.size(); ++i)
    {
        int freqV1=frequency(v1, v1[i]);
        int freqV2=frequency(v2, v1[i]);
        int to_add;
        if(frequency(common,v1[i]) == 0)
        {
            if(freqV1>freqV2) // whichever frequence is smaller, it adds that many elements to the common elements vector.
            {
                to_add=freqV2;
            }
            else
            {
                to_add=freqV1;
            }
            for (int j=0; j < to_add; ++j) //adds the element by the amount of "to_add"
            {
                common.push_back(v1[i]);
            }
        }
    }
    return common; // returns the vector
}

vector<int> not_in_the_other_vector(const vector<int> &v1, const vector<int> &v2)
{
// this function gives a new vector that finds all the elements that are only in one of the vecotrs
    vector<int> not_in;
    for(int i=0; i<v1.size(); ++i)
    {
        int freqV2=frequency(v2, v1[i]); // if the frequency of v2 of v[i] is 0 then we know that v[i] is not in v1
        if (freqV2==0)
        {
            for (int j=0; j<1; ++j)
            {
                not_in.push_back(v1[i]); // so then it adds it to that new vector
            }
        }
    }
    return not_in;
}

vector<int> unique(const vector<int> &v1, const vector<int> &v2) // gets every element within the two vectors once.
{
    vector<int> v;
    vector <int> add;
    add=v1; // first I make a new vector and copy the elements from v1 to it
    for(int i=0; i<v2.size(); ++i)
    {
        add.push_back(v2[i]); // then I add the elements of v2 to the new vector I just created
    }
    bool found = false;
    v.push_back(add[0]);
    for (int i=0; i<add.size(); ++i)
    {
        for (int j=0; j<v.size()+1; ++j)
        {
            if(v[j]==add[i]) // so that we don't copy elements twice, I use the "found" variable
                found = true;
        }
        if(!found) // if it is not found, then I know the element is unique, so I'll add it to the vector that i want to return
            v.push_back(add[i]);
        found=false;
    }
    return v;
}

int main() {
    srand((int)time(0)); // seeds the random number generator
    vector<int> v1; // vector initations
    vector<int> v2;
    vector<int> common;
    vector<int> ov1;
    vector <int> ov2;
    vector <int> v3;
    int size_v1; // used to determine the sizes of the vectors
    int size_v2;
    
    cout << "How big do you want \"v1\" to be? "; // user can input the desired sizes of v1 and v2
    cin >> size_v1;
    v1.resize(size_v1);
    cout << "How big do you want \"v2\" to be? ";
    cin >> size_v2;
    v2.resize(size_v2);
    
    fill_vector(v1); // fills the vectors and then outputs them below
    fill_vector(v2);
    
    cout << endl << "Vector V1 contents: ";
    output(v1);
    cout << endl << endl << "V2 contents: ";
    output(v2);
    cout << endl << endl << "Elements that are common to both vectors: ";
    common=common_elements(v1, v2); // calls the function to determine the common elements
    output(common);
    cout << endl << endl << "Elements that are in V1, but not in V2: ";
    ov1=not_in_the_other_vector(v1, v2); // and the only function to determine the only elements
    output(ov1);
    cout << endl << endl << "Elements that are in V2, but not in V2: ";
    ov2=not_in_the_other_vector(v2, v1);
    output(ov2);
    cout << endl << endl << "Unique elements of V1 and V2: "; // finally gets to the unique elements
    v3=unique(v1,v2); // and calls the function to determine it
    output(v3);
    cout << endl << endl << endl;
    
    vector<Fraction> fraction_vector(100); // declares a vector of fractions of size 100
    fill_fraction(fraction_vector); // fills that vactor
    double max=max_fraction(fraction_vector); // determines the highest fraction in that vector
    cout << "The largest decimal value in your fraction vector is: " << max << endl; // outputs the highest fraction
    
    system("pause");
    return 0;
}