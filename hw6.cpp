/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #6
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program allows the user to input a phrase.
 The program then takes the phrase and analyzes the number of sentences,
 words, and syllables included in the phrase. It then runs the Flesch
 test to determine the readability of the phrase.
 
 List of known bugs: None.
 ***********************************************************************/


#include <iostream>
#include <string>

using namespace std;


bool is_punctuation (string s) // This function returns true for punctuation marks that indicate a sentence.
{ // I will later use this function in my sentence counter.
    string punctuation = s.substr(0,1);
    if (s.length()==0)
        return false;
    else if (punctuation == "." || punctuation == "?" || punctuation == "!" || punctuation == ":" || punctuation == ";")
        return true;
    else
        return false;
}

bool is_vowel (string s) // This function returns true if it comes across a character that is a vowel, which I will later use
// for counting syllables.
{
    string vowel = s.substr(0,1);
    if (s.length()==0)
        return false;
    else if (vowel == "A" || vowel == "a" || vowel == "I" || vowel == "i" || vowel == "O" || vowel == "o" ||
             vowel == "U" || vowel == "u" || vowel == "Y" || vowel == "y")
        return true;
    else
        return false;
}


bool is_e (string s) // Because "e" has separate rules, I found that it would be easier to distinguish an "e" as it's own type
{ // therefore I made this function, similar to the vowel function, to distinguish an "e".
    string e = s.substr(0,1);
    if (s.length()==0)
        return false;
    else if (e == "E" || e=="e")
        return true;
    else
        return false;
}

int get_punctuation (string s)
{
    int b;
    int n=(int)s.length();
    if (s == "") // accounts for empty strings
        b=0;
    else
        b=1;
    for (int i=0; i<n; ++i)
    {
        if (is_punctuation(s.substr(i, n-i))) // analyzes string character by character to check for punctuation marks
        {
            if (i==0)
            {
                if(is_punctuation(s.substr(i,n-i)))
                    ++b;
            }
            else if (i!=0)
            {
                //if(!is_punctuation(s.substr(i-1,n-i))) //makes sure that repeating punct. marks (ellipses etc...) are not counted.
                ++b; // ex: "hi!!!!" is 1 sentence not four. Uncomment the if statement above to get the result.
            }
        }
    }
    if (n!=0 && is_punctuation(s.substr(n-1,1)))
        b-=1; // if the user_phrase ends with punctuation, this will take off one from b to account for b starting at 1.
    return b;
}

string get_word (string &s) // This string takes the user_phrase and takes a word one-by-one and sends it through
{ // the syllable counting function.
    string word="";
    int i=0;
    int n=(int)s.length();
    while (i<n && (s.substr(i,1) == " " || is_punctuation(s.substr(i,1)))) //skips spaces a punctuation
        ++i; // adds on to "i" to move through the string
    while (s.substr(i,1) != " " && !is_punctuation(s.substr(i,1)) && i<n) // if the character is a letter, then it does this
    {
        word+=s.substr(i,1); // This adds each character to build the word.
        ++i;
    }
    s=s.substr(i,s.length()); // finally we get the whole word
    return word; // The word is returned!!
}

int get_vowel (string s) // Here is the vowel counting function, by counting vowels we can tell how many syllables are in a word.
{
    int b=0; // b is our number of vowels (~syllables)
    int n=(int)s.length();
    if (s == "") // If the user gives an empty string, we of course want to return 0
        b=0;
    for (int i=0; i<n; ++i)
    {
        if (is_vowel(s.substr(i,n-i)) || is_e(s.substr(i, n-i))) // if the character is a vowel or an e
        {
            if (i==0) // if its at the first character of the word
                ++b; // add to b, this is mainly to compare double vowels, since double vowels count as 1 syllable
            else if (!is_vowel(s.substr(i-1,n-i)) && !is_e(s.substr(i-1,n-i))) //if the vowel is not repeating, then count it
                ++b; // if the vowel is repeating it doesn't count.
        }
    }
    if (n!=0) // (not an empty string)
    {
        if (is_e(s.substr(n-1,1))) // special rule for e!! if e is not the last letter
        {
            if (!is_vowel(s.substr(n-2,1))) // and a letter precedes it
            {
                if(!is_e(s.substr(n-2,1))) // and another e does not precede it
                    --b; // don't count it!!! e.g. "have"
            }
        }
    }
    if (b<1) // if we get a word that doesn't match the rules, we will set b to 1 so that each word
        b=1; // has at least one syllable
    if (n==0) //unless of course the string is empty again
        b=0;
    return b;
}

double flesch_test(int words, int sentences, int syllables)
{
    // Test equation:
    // Index = 206.835 - 84.6 * (syllables/Words) - 1.015 * (words/sentences)
    const double num1 = 206.835; // These are all constants. But not hard-coded in so they can easily be changed later
    const double num2 = 84.6;
    const double num3 = 1.015;
    double result;
    
    if (words != 0 && sentences !=0) // Since there is a possibility of a divide by 0 error, we want to only run the test if
    { // the user enters at least 1 word and 1 sentence (not an empty string)
        result = num1-num2*((double)syllables/words)-num3*((double)words/sentences);
        return result;
    }
    else // if the user does, we will just display an error message.
    {
        result = 404; // I just arbitrarily chose this number as an error number. According to the Wikipedia article
        // the Flesch test can't get that high so that number is fine.
    }
    return result;
}

int main()
{
    string user_phrase;
    cout << "Enter a phrase. "; // prompts user to enter a phrase
    getline(cin, user_phrase); // gets the entire phrase
    int se = get_punctuation(user_phrase); // returns number of sentences
    int sy=0; // initially syllables will be 0
    string word;
    int w=0; // intially words will be 0
    do {
        word=get_word(user_phrase); // sends string through the function to get indifidual words
        if (word != "")
            w++; // counts how many times it has been looped (how many words there are)
        sy = sy + get_vowel(word); // sends that word through the get_vowel function
    } while (user_phrase!=""); // until it reaches the end of/empty string
    
    cout << endl << "Your input returned..." << endl;
    if (sy==1) // grammatically correct
        cout << sy << " syllable" << endl;
    else
        cout << sy << " syllables" << endl;
    if (w==1)
        cout << w << " word" << endl;
    else
        cout << w << " words" << endl;
    if (se==1)
        cout << se << " sentence" << endl;
    else
        cout << se << " sentences" << endl;
    cout << endl;
    double test;
    test=flesch_test(w, se, sy);
    if (test==404)
        cout << "Error. Rerun and enter a phrase to evaluate." << endl;
    else
        cout << "Your index is: " << test << endl;
    
    system("pause");
    return 0;
    
}