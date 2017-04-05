/***********************************************************************
 Ethan Blank                        PIC 10A Intro. to Programming
 ID: 204381410                      Spring 2016
 Email: ethanrb@gmail.com           Homework #7
 Section: 2B
 Honesty Pledge:
 
 I, Ethan Blank, pledge that this is my own independent
 work, which conforms to the guidlines of academic honesty as
 described in the course syllabus.
 
 Description of program: This program is a game where the user draws two
 cards and then must bet whether or not the next card that they pull is
 between those cards. If the card is between then the user wins, if not
 then it loses by the amount of the bet. This program demonstrates
 use of developer-written-classes.
 
 List of known bugs: None.
***********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card // here is my card class
{
public:
    Card();
    string get_rank_string() const;
    string get_suite_string() const;
    int get_rank() const;
  
private:
    int rank;
    int suit;
};

Card::Card()
{
    rank = (rand()%13) + 1; //randomizes the rank from [1,13]
    suit = (rand()%4) + 1; // randomizes the suit from [1,4]
}

string Card::get_rank_string() const // where the value of the card gets assinged to a string
{
    switch (rank)
    {
        case 1:
            return "Ace";
            break;
        case 2:
            return "Two";
            break;
        case 3:
            return "Three";
            break;
        case 4:
            return "Four";
            break;
        case 5:
            return "Five";
            break;
        case 6:
            return "Six";
            break;
        case 7:
            return "Seven";
            break;
        case 8:
            return "Eight";
            break;
        case 9:
            return "Nine";
            break;
        case 10:
            return "Ten";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
        default:
            return "Error";
            break;
    }
}

string Card::get_suite_string() const // value of the suit is converted to a string
{
    switch (suit)
    {
        case 1:
            return "Diamonds";
            break;
        case 2:
            return "Hearts";
            break;
        case 3:
            return "Spades";
            break;
        case 4:
            return "Clubs";
            break;
        default:
            return "Error";
            break;
    }
}

int Card::get_rank() const //returns the rank of the card
{
    return rank;
}

class Player // here is my player class
{
public:
    Player(string newPerson, int newMoney); // the player gets assinged a string and a number
    int get_money() const;
    void update_money(int dMoney);
    
private:
    string person;
    int money;
};

Player::Player(string newPerson, int newMoney) // here is where the info is stored
{
    person=newPerson;
    money=newMoney;
}


int Player::get_money() const // returns how much moeny the person has
{
    return money;
}

void Player::update_money(int dMoney) // adds to the score by dMoney
{
    money+=dMoney;
}

int check_bet (int a, int b) // this function checks if the player bets too high. if they do then they must place a new bet
{
    if (b > a)
    {
        while (b > a)
        {
            cout << "I wish I were made of money too... unfortunately we're not, so make another bet that's below your total. ";
            cin >> b;
        }
        return b;
    }
    else
        return b;
}

bool is_between (Card A, Card B, Card C) // checks to make sure that the third card is in between the first ones
{
    if ((A.get_rank() <= C.get_rank() && C.get_rank() <= B.get_rank()) || (B.get_rank() <= C.get_rank() && C.get_rank() <= A.get_rank()))
        return true;
    else
        return false;
}


int main() {
    srand((int)time(0)); // randomizes the page in the random book by time
    cout << "Hello. What is your name? ";
    string name;
    cin >> name;
    cout << "\nHello, " << name << "! Open up your wallet and let me know how much money you have. Whole numbers only please! ";
    int money;
    cin >> money;
    Player first(name, money); // here the player is finally introduced
    cout << endl;
   
    do {
        cout << name << " you have $" << first.get_money() << '.' << endl; // utilizing the member functions
        Card A;
        Card B;
        cout << "You got a " << A.get_rank_string() << " of " << A.get_suite_string() << " and a " << B.get_rank_string() << " of " << B.get_suite_string() << '.' << endl;
        cout << "How much do you want to bet that the next card is in between? ";
        int bet;
        cin >> bet;
        bet = check_bet(first.get_money(), bet); // using the check bet function
        Card C;
        cout << "You draw a " << C.get_rank_string() << " of " << C.get_suite_string() << ".\n";
        if (is_between(A, B, C)) // using the is between function
        {
            cout << "YES, " << name << "!!! You win $" << bet << ".\n\n";
            first.update_money(bet); // if its true the player wins by the bet, the computer loses
        }
        else
        {
            cout << "Sorry " << name << " you lose $" << bet << ".\n\n";
            first.update_money(-bet); // the computer wins; player loses by the bet
        }
    } while (first.get_money() <= 10*money && first.get_money() != 0); // goes until the player makes 10xhis original money or the player loses all his money
    if (first.get_money() !=0)
        cout << "Congrats " << name << "! You ended up with $" << first. get_money() << ".\n";
    else
        cout << "Sorry, " << name << ". You ended up with $0." << endl;
    
    
    system("pause");
    return 0;
}
