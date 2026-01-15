// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source)
:head(nullptr) , tail(nullptr) {
     Node* curr = source.head;
     while(curr){
        this->push_back(curr->info);
        curr = curr->next;
     }


    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = this->head;
    Node*temp = curr;
    while(curr){
        curr = curr->next;
        delete temp;
        temp = curr;
    }
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = this->head;
    while(curr){
        sum+=curr->info;
        curr = curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = this->head;
    while(curr){
        if(curr->info == value){
            return true;
        }
        curr = curr->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!this->head)
        return 0;
    int Max = this->head->info;
    Node* curr = this->head->next;
    while (curr) {
        if (curr->info > Max){
            Max = curr->info;
        }
        curr = curr->next;
    
    }
    return Max; 
}
// REPLACE THIS NON-SOLUTION


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!this->head)
        return 0.0;
    double sum = 0.0;
    double count = 0.0;
    Node*curr = this->head;
    while(curr){
       sum+= curr->info;
       count = count + 1.0;
       curr = curr->next;
    }
    double avg = sum/count;
    return avg; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node*p = new Node;
    p->info = value;
    p->next = this->head;
    this->head = p;
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    Node*p = new Node;
    p->info = value;
    if(this->head == nullptr){
        this->head = p;
        tail = p;
        p->next = nullptr;
    }
    else{
        this->tail->next = p;
        tail = p;
        p->next = nullptr;
    }   
    // IMPLEMENT
 
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   int count = 0;
    Node* curr = this->head;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENTif
    if(this == &source){ return *this; }
    Node* curr = this->head;
    Node*temp = curr;
    while(curr){
        curr = curr->next;
        delete temp;
        temp = curr;
    }
    this->head = nullptr;
    this->tail = nullptr;

    Node* purr = source.head;
     while(purr){
        this->push_back(purr->info);
        purr = purr->next;
     }
    
    return *this;
}

// constructor sets up empty list
IntList::IntList() : head(nullptr) , tail(nullptr) { 
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

