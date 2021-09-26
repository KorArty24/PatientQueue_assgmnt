

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
    int  *ptr = NULL;
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
    (void) value;
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
}

PatientNode parseStringValue(std::string &token,PatientNode node){
    int pos=token.find("");
    node.name=token.substr(0,pos);
    node.priority=stoi(token.substr((pos+1),token.length()));
}
