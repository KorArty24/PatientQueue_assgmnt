

/*************************************************************
 * File: SinglyLinkedListPQueue.cpp
 *
 * Implementation file for the SinglyLinkedListPriorityQueue
 * class.
 */
 
#include "SinglyLinkedListPQueue.h"
#include "error.h"
#include "patientnode.h"
using namespace std;

SinglyLinkedListPriorityQueue::SinglyLinkedListPriorityQueue() {
    firstnode = NULL;
}

SinglyLinkedListPriorityQueue::~SinglyLinkedListPriorityQueue() {
    PatientNode *current=firstnode;
    while (hasNext(*current)){
        PatientNode *next = current->next;
        delete[] current;
        current=next;
 }
    delete[] current;
}

int SinglyLinkedListPriorityQueue::size() const {
	// TODO: Fill this in!
	
    return countElements();
}

bool SinglyLinkedListPriorityQueue::isEmpty() const {

    if (firstnode==NULL) return true;
}

void SinglyLinkedListPriorityQueue::enqueue(const string& value) {
    PatientNode newnode=createNode(value);
    PatientNode *currentNode=firstnode;
    PatientNode *nextnode=currentNode->next;
    PatientNode *previous;
    int count;
    if (isEmpty()){ //enqueue into the empty list
    *firstnode = newnode;
    } else if ((firstnode->priority>newnode.priority)){
        newnode.next=firstnode;
        firstnode= &newnode;
    } else{
        //count=1;
        while(!hasNext(*currentNode)){
            if ((newnode.priority < nextnode->priority)&&
                           (newnode.priority >=currentNode->priority))
            {
                currentNode->next=&newnode; //insert in the middle
                newnode.next=nextnode;
            }
            currentNode=currentNode->next;
        }
        if (currentNode->next==NULL){
            currentNode->next=&newnode;
        }
       }
      }



string SinglyLinkedListPriorityQueue::peek() const {
    try {
        if (!isEmpty()) {
            return firstnode->name;
        } else {
            throw (NULL);
        }

    }  catch (...) {
        cout << "There are no patients in the list! \n";
    }
}

string SinglyLinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
    try {
        if (firstnode!=NULL) {
            if (firstnode->next!=NULL){
                PatientNode *second=firstnode->next;
                PatientNode *temp=firstnode;
                firstnode=second;
                delete [] temp;
                string Name = firstnode->name;
                return Name;
            } else {
                PatientNode *temp;
                temp=firstnode;
                firstnode=NULL;
                string Name = temp->name;
                return Name;
            }
        } else if (isEmpty()) {
            throw (NULL);
        }

    }  catch (...) {
        cout << "There are no patients in the list! \n";
    }
    //return "";
}

int SinglyLinkedListPriorityQueue::countElements() const {
    int c=0;
    PatientNode *current=firstnode;
    if (firstnode->next==NULL){
    return 1;
    } else {
        while(!hasNext(*current)){
            c++;
            current=current->next;
        }
    }
    return c;
};

bool SinglyLinkedListPriorityQueue::hasNext(PatientNode node) const{
    return node.next!=NULL;
};

PatientNode SinglyLinkedListPriorityQueue::createNode(const string &token) const {
    int pos=token.find("");
    std::string name=token.substr(0,pos);
    int priority=stoi(token.substr((pos+1),token.length()));
    return *(new PatientNode(name,priority));

}


