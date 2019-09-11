//  Author: James Sipowicz III
//  Serial	Number: N/A
//  Due Date: 02/06/19
//  Programming Assignment	#: 1
//  Spring	2019 - CS3358 -	Section 253
//
//  Instructor: Husain	Gholoom
//
//  > This project based on the Pico, Fermi & Bagel Game.
//  > The program generates three random numbers, the user has 10 tries
//  > to guess which numbers were created through three types of hints.
//  > • If a guess has no correct numbers, it will respond: "B"
//  > • For each correct number in wrong order, it will respond: "P"
//  > • For each correct number in correct order, it will respond "F"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int numGuesses = 10;
int random(){
    return(1+rand()%9);
}
int main(){  //  Main Method
    bool isSolved = false;
    char repeatKey = 'Y';
    int userGuess, guessOne, guessTwo, guessThree;
    cout << "Welcome to my Game Program." << endl;
    cout << endl;
    cout << "I am thinking of a 3-digit number. Try to guess what it is. Here are some" << endl;
    cout << "clues:" << endl;
    cout << endl;
    cout << "When I say: _, it means: " << endl;
    cout << endl;
    cout << "  B: No digit is correct" << endl;
    cout << "  P: One digit is correct but in the wrong position." << endl;
    cout << "  F: One digit is correct and in the right position." << endl;
    cout << endl;
    while(repeatKey == 'y' || repeatKey == 'Y'){
        // Beginning of Game
        cout << "I have thought up a number. You have 10 guesses to get it." << endl;
        cout << endl;
        srand(time(NULL));
        int one = random();
        int two = random();
        int three = random();
        while ((one == two) || (one == three) || (two == three)){
            one = random();
            two = random();
            three = random();
        }
        for (int i = 0; i < numGuesses; i++){
            cout << "Player guess # " << i+1 << ": " << endl;
            cin >> userGuess;
            // Exception Handling
            if (userGuess < 001 || userGuess > 1000){
                cout << "You've entered an incorrect digit" << endl;
                continue;
            }
            // To solve what the guess is, I will go through each number
            // in order and check if it triggers any of our hints.
            // First we will separate the guess into our int variables:
            // - guessOne, guessTwo, guessThree
            guessOne = userGuess / 100;
            guessTwo = (userGuess % 100)/10;
            guessThree = userGuess % 10;
            // First step: check if all are wrong
            cout << one << two << three << endl;
            if (guessOne == one && guessTwo == two && guessThree == three){
                isSolved = true;
            }else{
                if (guessOne == one){
                cout << "F ";
                }else if (guessOne == two || guessOne == three){
                cout << "P ";
                }if (guessTwo == two){
                cout << "F ";
                }else if(guessTwo == one || guessTwo == three){
                cout << "P ";
                }if (guessThree == three){
                cout << "F ";
                }else if(guessThree == one || guessThree == two){
                cout << "P ";
                }else{
                cout << "B " << endl;
            }
            cout << endl;
            continue;
        }
        if (isSolved == true){
            cout << "You got it!" << endl;
            break;
            }else{
            cout << "Sorry, you exceeded your number of guesses." << endl;
            cout << "The number you were trying to guess was: " << one << two << three << endl;
            break;
            }
        }
        // End of Game
        cout << "Do you want to play again? (y/n) ";
        cin >> repeatKey;
    }
}
