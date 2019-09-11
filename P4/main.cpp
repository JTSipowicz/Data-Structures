// Author: James Sipowicz & Jakob Arsement
// Serial: 40 + 3
// Group: 15
// Due Date: 03/27/19
// Programming Assignment Number: 4
// Spring 2019 - CS3358
// Section Number: 253
// Instructor: Husain Gholoom
/*
This program implements four different singly linked Lists that utilize pointers.
The first two Lists (list_1 and list_2) are populated with 15 randomized integers
between 0 and 25. The third List (list_3) contains all 30 elements of list_1 and
list_2. The fourth List (list_4) includes all no-duplicate values from list_3.

    • List 4
        - Values 100 and 200 are to be inserted at the first two positions.
        - Values 88 and 99 are to be appended at the end.
        - Display
        - Return number of elements
        - Delete first and last element
        - Display Backwards
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
    public:
        Node* next;
        int data;
};
class LinkedList{
    public:
        int length;
        Node* head;

        LinkedList();
        ~LinkedList();
        void add(int data);
        void print();
};
LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}
LinkedList::~LinkedList(){
    cout << "LIST DELETED" << endl;
}
void LinkedList::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}
void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        cout << head->data << " ";
        head = head->next;
        i++;
    }
    cout << "List Length is: " << i-1 << endl;
}
int main(int argc, char const *argv[]){
    LinkedList* list_1 = new LinkedList();
    LinkedList* list_2 = new LinkedList();
    LinkedList* list_3 = new LinkedList();
    LinkedList* list_4 = new LinkedList();
    for (int i = 0; i < 15; ++i){
        list_1->add(rand() % 26);
    }
    for (int i = 0; i < 15; ++i){
        list_2->add(rand() % 26);
    }
    list_1->print();
    list_2->print();
    delete list_1;
    delete list_2;
    return 0;
}
