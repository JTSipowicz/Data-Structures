//  Author: James Sipowicz III
//  Serial	Number: 40
//  Due Date: 02/19/19
//  Programming Assignment	#: 2
//  Spring	2019 - CS3358 -	Section 252
//  Instructor: Husain	Gholoom
//
//  > This program will encode and decode a secret message
//  > that only the sender and recipient could read. Using
//  > ciphers, the user will enter a specific key in an
//  > attempt to correctly decode an encrypted string.
//  > • If the key is incorrect, message will stay encoded.
//  > • Message can only be: a-z, A-Z, 0-9
//  > •
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;
void decrypt(int, string);
void encrypt(int, string);
// *** Main Method
int main(){
    string userChoice;
    string userMessage;
    int key;
    cout << "Welcome to cryptography" << endl;
    while(1){
        cout << "What would you like to do to a message? (encrypt, decrypt, exit)" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        if(userChoice == "encrypt"){
            cout << "Enter your message: " << endl;
            cin.ignore(); // Clear previous cin  ? possible ignore
            getline(cin, userMessage);
            cout << "Enter the key number:(1-35) " << endl;
            cin >> key;
            while(1){
                if(cin.fail() || ((key < 1) || (key > 35))){
                    cin.clear(); // Clear previous cin
                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                    cout << "Error: Please enter an integer:(1-35) ";
                    cin >> key;
                }
                if(!cin.fail())
                    break;
            }
            encrypt(key, userMessage);
        }
        else if(userChoice == "decrypt"){
            cout << "Enter the key number:(1-35) " << endl;
            cin >> key;
            while(1){
                if(cin.fail() || ((key < 1) || (key > 35))){
                    cin.clear(); // Clear previous cin
                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                    cout << "Error: Please enter an integer:(1-35) ";
                    cin >> key;
                }
                if(!cin.fail())
                break;
            }
            cout << "Enter your message:" << endl;
            cin.ignore();
            getline(cin, userMessage);
            decrypt(key, userMessage);
        }
        else if(userChoice == "exit"){
            break;
        }
        else{
            cout << "Invalid message" << endl;
        }
    }
    cout << "James Sipowicz Security Systems" << endl;
    cout << "2-19-2019" << endl;
    return 0;
}
int search(vector<char> vect, int vectCapacity, char searchChar){
    int temp;
    if(vect[vectCapacity - 1] == searchChar){
        return vectCapacity - 1;
    }
    temp = vect[vectCapacity - 1];
    vect[vectCapacity - 1] = searchChar;
    for(int i = 0;; i++){
        if(vect[i] == searchChar){
            vect[vectCapacity - 1] = temp;
            if(i < vectCapacity - 1)
                return i;
            return -1;
        }
    }
}
void decrypt(int shiftingInt, string userMessage){
    vector<char> alphabetIncludingNumbers(36); //Initializes a 1-D vector (a-z + 0-9)
    vector<vector<char>> code(2, alphabetIncludingNumbers);//Initializes a 2-D vector
    for(int i = 0; i < userMessage.size(); i++)
    userMessage[i] = toupper(userMessage[i]);
    for(int i = 0; i < code.size(); i++){
        for(int j = 0; j < code[i].size(); j++){
            if(j < 26){
                code[0][j] = 'A' + j;
            }
            if(j >=  26){
                code[0][j] = '0' + (j % 26);
            }
            code[1][j] = code[0][(j + shiftingInt) % 36];
        }
    }
    for(int i = 0; i < code[1].size(); i++){
        int result;
        result = search(code[0], code[0].size()-1, userMessage[i]);
        (result == -1) ? userMessage[i] = ' ': userMessage[i] = code[0][result];
    }
    cout << userMessage << endl;
}
void encrypt(int shiftingInt, string userMessage){
    vector<char> alphabetIncudingNumbers (36);  //Initializes a 1-D vector a-z + 0-9
    vector<vector<char>> code(2, alphabetIncudingNumbers);//Initializes a 2-D vector
    for(int i = 0; i < userMessage.size(); i++)
    userMessage[i] = toupper(userMessage[i]);
    for(int i = 0; i < code.size(); i++){
        for(int j = 0; j < code[i].size(); j++){
            if (j < 26){
                code[0][j] = 'A' + j;
            }
            if(j >= 26){
                code[0][j] = '0' + (j % 26);
            }
            code[1][j] = code[0][(j + shiftingInt)% 36];
        }
    }
    for(int i = 0; i < userMessage.size(); i++){
        int result;
        result = search(code[0], code[0].size()-1 , userMessage[i]);
        (result == -1) ? userMessage[i] = ' ': userMessage[i] = code[1][result];
    }
    cout << userMessage << endl;
}
