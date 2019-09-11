// Author: James Sipowicz & Jakob Arsement
// Serial: 40 + 3
// Group: 15
// Due Date: 04/08/19
// Programming Assignment Number: 5
// Spring 2019 - CS3358
// Section Number: 253
// Instructor: Husain Gohloom
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int arraySize;
    char repeatKey;
    bool repeat = false;
    cout << "Welcome to my Recursion Program" << endl;
    while(repeat == false){
        cout << "Please enter the size of the desired array: ";
        cin >> arraySize;
        int intArray[arraySize];
        if(arraySize >= 5){
            for(int i = 0; i < arraySize; i++){
                intArray[i] = 10 + rand()%365;
            }
        }else{
        cout << "The array size is too small" << endl;
        continue;
        }
        cout << "Generated Array: " << endl;
        for (int i = 0; i < arraySize; i++){
            cout << intArray[i] << " ";
        }
        cout << endl << endl;

        //TODO --- MAKE RECURSIVE ---
        /*  Reverse Display Recursive Function */
        cout << "Generated Array Reversed: " << endl;
        for (int i = arraySize; i--; i < 0){
            cout << intArray[i] << " ";
        }
        cout << endl << endl;
        /*  Square of Integers Function */
        /*
            Powers of i from range 1 to the first number element
            generated in the array. Ascending Order.
        */
        cout << "Square of Integers from 1 to first element" << endl;
        int firstElement = intArray[0];
        for (int i = 0; i < firstElement; i++){
            cout << i * i << " ";
        }
        cout << endl << endl;
        /*  Raise Number to a Power Function */
        cout << "Raise Number to the Power of 2 for the last element: " << endl;
        int lastElement = intArray[arraySize-1];
        int lastElementPowered = lastElement * lastElement;
        cout << "Last Element to the Power of 2 is: " << lastElementPowered;
        cout << endl << endl;
        /*  Check if element is prime Function */
        cout << "Determine which elements are prime" << endl;
        int temp, i, j;
        bool isPrime = true;
        for(i = 0; i < arraySize; i++){
            temp = intArray[i];
            for(j = 2; j <= temp; j++){
                if(temp % j == 0){
                    isPrime = false;
                    break;
                }
            if(isPrime)
                cout << temp << " ";
            }
        }
        cout << endl;
        cout << "Do you want to enter another number? (y/n) ";
        cin >> repeatKey;
        if(repeatKey == 'n' || 'N'){
            break;
        }else{
            continue;
        }
    }
    cout << "Implemented by James Sipowicz & Jakob Arsement" << endl;
    return 0;
}
