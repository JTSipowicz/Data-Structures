// Author: James Sipowicz & Jakob Arsement
// Serial: 40
// Group: 15
// Due Date: 04/17/19
// Programming Assignment Number: 6
// Spring 2019 - CS3358
// Section Number: 253
// Instructor: Husain Gholoom
/*

*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

bool checkContinue();
void displayArray(int, char[]);
char recursiveSequential(int, char[], int, int&);
void selectionSort(int, char[]);
void insertionSort(int, char[]);
void quickSortMiddle(char[], int, int, int&);
void quickSortFirst(char[], int, int, int&);
void quickSortLast(char[], int, int, int&);

int main(){
    srand(time(NULL));
    int n;
    char repeatKey;
    bool repeat = true;
    int sequentialComparisons = 0;
    int counterMiddle = 0;
    int counterFirst = 0;
    int counterLast = 0;
    char display80 = 80;
    cout << "***  Welcome to My Sorting APP  ***" << endl << endl;
    do{
        cout << "Enter the array size --> ";
        cin >> n;
        while(cin.fail() || n < 0){
            cout << endl;
            cout << "Error: Size must be an integer and > 0." << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter another value: ";
            cin >> n;
        }
        // Accepts positive integer (n) from the keyboard.
        if(n > 20){
            n = 20;
        }
        char charArray[n];
        // Using a random number generator, populate the array with
        // characters between 33 - 126.
        for(int i = 0; i < n; i++){
            charArray[i] = 33 + rand()%93;
        }
        char holdArray[n];              // Temporary Array to reset values
        for(int i = 0; i < n; i++){
            holdArray[i] = charArray[i];
        }
        // **************
        // FUNCTION CALLS
        // **************
        displayArray(n, charArray);         //display array
        if(recursiveSequential(n, charArray, 80, sequentialComparisons) == -1)
            cout << endl << "The array doesn't contain character " << display80 << endl;
        else
            cout << endl << "The array contains character " << display80 << endl;
        cout << "Number of Comparisons: " << sequentialComparisons << endl;
        selectionSort(n, charArray);
        cout << "Array Sorted using Selection Sort: ";
        displayArray(n, charArray);
        cout << endl;
        for(int i = 0; i < n; i++){         //reset original charArray
            charArray[i] = holdArray[i];
        }
        insertionSort(n, charArray);
        cout << "Array Sorted using Insertion Sort: ";
        displayArray(n, charArray);
        for(int i = 0; i < n; i++){         //reset original charArray
            charArray[i] = holdArray[i];
        }
        cout << endl;
        quickSortMiddle(charArray, 0, n-1, counterMiddle);
        cout << "Array Sorted using QuickSort with Middle Pivot: ";
        displayArray(n, charArray);
        cout << endl;
        cout << "Number of Recursive calls: " << counterMiddle << endl;
        for(int i = 0; i < n; i++){         //reset original charArray
            charArray[i] = holdArray[i];
        }
        quickSortFirst(charArray, 0, n-1, counterFirst);
        cout << "Array Sorted using QuickSort with First Pivot: ";
        displayArray(n, charArray);
        cout << endl;
        cout << "Number of Recursive calls: " << counterFirst << endl;
        for(int i = 0; i < n; i++){         //reset original charArray
            charArray[i] = holdArray[i];
        }
        quickSortLast(charArray, 0, n-1, counterLast);
        cout << "Array Sorted using QuickSort with Last Pivot: ";
        displayArray(n, charArray);
        cout << endl;
        cout << "Number of Recursive calls: " << counterLast << endl;
        for(int i = 0; i < n; i++){         //reset original charArray
            charArray[i] = holdArray[i];
        }
        repeat = checkContinue(); //check if user wants to continue
        }while(repeat == true);
    cout << "Implemented by James Sipowicz & Jakob Arsement" << endl;
    cout << "04 - 08 - 2019";
}
// END
bool checkContinue(){
    int error = 0;
    do{
        char userContinue;
        cout << endl <<"Would you like to test a new array? (y/n): ";
        cin  >> userContinue;
        cout << endl;
        if(userContinue == 'y' || userContinue == 'Y')
            return true;
        else if(userContinue == 'n' || userContinue == 'N')
            return false;
        else{cout << endl << "Invalid Input...\n"; error = -1;}
    }while(error == -1);
}
void displayArray(int n, char charArray[]){
    cout << endl << "The generated array is: ";
    for (int i = 0; i < n; i++){
        cout << charArray[i] << " ";
    }
}
char recursiveSequential(int n, char charArray[], int value, int& sequentialComparisons){
    if(n == 0)
        return -1;
    if(value == charArray[n-1])
        return n - 1;
    sequentialComparisons++;
    return recursiveSequential(n - 1, charArray, value, sequentialComparisons);
}
void selectionSort(int n, char SSArray[]){
      int i, j, minIndex, temp;
      for (i = 0; i < n - 1; i++){
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (SSArray[j] < SSArray[minIndex])
                        minIndex = j;
            if (minIndex != i){
                  temp = SSArray[i];
                  SSArray[i] = SSArray[minIndex];
                  SSArray[minIndex] = temp;
            }
      }
}
void insertionSort(int n, char ISArray[]){
      int i, j, temp;
      for (i = 1; i < n; i++){
            j = i;
            while(j > 0 && ISArray[j - 1] > ISArray[j]){
                temp = ISArray[j];
                ISArray[j] = ISArray[j - 1];
                ISArray[j - 1] = temp;
                j--;
            }
      }
}
void quickSortMiddle(char charArray[], int left, int right, int& counterMiddle){
    int i = left, j= right;
    int temp;
    int pivot = charArray[(left + right) / 2];
    while (i <= j){
        while (charArray[i] < pivot)
            i++;
        while (charArray[j] > pivot)
            j--;
        if (i <= j){
            temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
            i++;
            j--;
        }
    };
    if(left < j){
        quickSortMiddle(charArray, left, j, counterMiddle);
        counterMiddle++;
    }
    if(i < right){
        quickSortMiddle(charArray, i, right, counterMiddle);
        counterMiddle++;
    }
}
void quickSortFirst(char charArray[], int left, int right, int& counterFirst){
    int i = left, j= right;
    int temp;
    int pivot = charArray[left];
    while (i <= j){
        while (charArray[i] < pivot)
            i++;
        while (charArray[j] > pivot)
            j--;
        if (i <= j){
            temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
            i++;
            j--;
        }
    };
    if(left < j){
        quickSortFirst(charArray, left, j, counterFirst);
        counterFirst++;
    }
    if(i < right){
        quickSortFirst(charArray, i, right, counterFirst);
        counterFirst++;
    }
}
void quickSortLast(char charArray[], int left, int right, int& counterLast){
    int i = left, j= right;
    int temp;
    int pivot = charArray[right];
    while (i <= j){
        while (charArray[i] < pivot)
            i++;
        while (charArray[j] > pivot)
            j--;
        if (i <= j){
            temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
            i++;
            j--;
        }
    };
    if(left < j){
        quickSortLast(charArray, left, j, counterLast);
        counterLast++;
    }
    if(i < right){
        quickSortLast(charArray, i, right, counterLast);
        counterLast++;
    }
}
