

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
    clear();
}

int SinglyLinkedListPriorityQueue::size() const {
	// TODO: Fill this in!
	
    return count;
}

bool SinglyLinkedListPriorityQueue::isEmpty() const {
	// TODO: Fill this in!
	
	return true;
}

void SinglyLinkedListPriorityQueue::enqueue(const string& value) {
    PatientNode newnode=createNode(value);
    if (firstnode==NULL){
    *firstnode = newnode;
    } else if (firstnode->priority>newnode.priority){
        newnode.next=firstnode;
    } else {

        PatientNode *nextnode=firstnode;
        PatientNode *previous;
        while(true){
            //PatientNode *nextnode = node->next;
            if((newnode.priority) < (nextnode->priority)){
                PatientNode *temp=nextnode;
                newnode.next=nextnode;
                previous->next=&newnode;

            } else if (newnode.priority >= nextnode->priority) {

            }
        }
    }

}

string SinglyLinkedListPriorityQueue::peek() const {
	// TODO: Fill this in!
	
	return "";
}

string SinglyLinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	
	return "";
}

int SinglyLinkedListPriorityQueue::count(){
    return 0;
};

bool SinglyLinkedListPriorityQueue::hasNext(PatientNode node){
    return node.next==NULL;
};

PatientNode SinglyLinkedListPriorityQueue::createNode(const string &token) const {
    int pos=token.find("");
    std::string name=token.substr(0,pos);
    int priority=stoi(token.substr((pos+1),token.length()));
    return *(new PatientNode(name,priority));

}
