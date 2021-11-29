/*************************************************************
 * File: HeapPQueue.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "HeapPQueue.h"
#include "error.h"
#include "patientnode.h"
#include <algorithm>
using namespace std;

const int INITIAL_CAPACITY = 20;
HeapPriorityQueue::HeapPriorityQueue() {
    capacity = INITIAL_CAPACITY;
    array = new PatientNode[capacity];

}

HeapPriorityQueue::~HeapPriorityQueue() {
    delete[] array;
}

int HeapPriorityQueue::size() const {
	// TODO: Fill this in!
	
	return 0;
}

bool HeapPriorityQueue::isEmpty() const {
	// TODO: Fill this in!
	
	return true;
}

void HeapPriorityQueue::enqueue(const string& value) {
  if (asize==capacity){
      expandCapacity();
  }
  array[asize]=createNode(value);
  if (array[asize].priority<
          array[asize/2].priority){
      swapElements(asize,asize/2);
  }
}

string HeapPriorityQueue::peek() const {
	// TODO: Fill this in!
	
	return "";
}

string HeapPriorityQueue::dequeueMin() {
    swapFirstAndLast(1,asize);
    restoreOrder();
}

PatientNode HeapPriorityQueue::createNode(const string &token) const {
    int pos=token.find("");
    std::string name=token.substr(0,pos);
    int priority=stoi(token.substr((pos+1),token.length()));
    return *(new PatientNode(name,priority));

}

void HeapPriorityQueue::restoreOrder(){

    for (int i=1;(2*i+1)<=asize;i++){
        int smallest = FindSmallest(2*i,2*i+1);
        if (array[i].priority<array[smallest].priority){
            PatientNode temp =array[smallest];
            array[smallest]=array[i];
            array[i]=temp;
        }
    }
}

int HeapPriorityQueue::FindSmallest(int i, int j){
    if (array[i].priority >= array[j].priority){
        return j;
    } else {
        return i;
    }
}

void HeapPriorityQueue::swapElements(int last, int root){
    if (array[last].priority<array[last/2].priority){
        return;
    }
    PatientNode temp = array[last];
    array[last]=array[last/2];
    array[last/2]=temp;
    last=last/2;
    swapElements(last,last/2);
}
