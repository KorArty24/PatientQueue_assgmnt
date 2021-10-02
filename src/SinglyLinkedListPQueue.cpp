

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
	// TODO: Fill this in!
    if (firstnode==NULL){
    *firstnode = createNode(value);
    } else {
        PatientNode newnode=createNode(value);
        PatientNode *node=firstnode;
        while(hasNext(*node)){
            PatientNode *nextnode = node->next;
            PatientNode *temp;
            if((newnode.priority) < (nextnode->priority)){
                temp=nextnode;
                newnode.next=nextnode;
                node->next=&newnode;
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
