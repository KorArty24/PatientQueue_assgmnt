/*******************************************************
 * File: SinglyLinkedListPQueue.h
 *
 * A priority queue class backed by a sorted, singly-linked
 * list.
 *
 * TODO: Answer the following questions:
 * What is the best-case runtime, in big-O notation, of inserting an
 * element into this priority queue? What is the worst-case runtime?
 *
 * What is the best-case runtime, in big-O notation, of removing an element
 * from this priority queue?  What is the worst-case runtime?
 *
 * You can sort a sequence of elements by inserting them all into a priority
 * queue, then removing them one at a time. If you use this priority queue,
 * you will end up with a well-known sorting algorithm. What sorting
 * algorithm is it?
 */
#ifndef PQueue_LinkedList_Included
#define PQueue_LinkedList_Included

#include <string>
#include "patientnode.h"
/* A class representing a priority queue backed by a sorted,
 * singly-linked list.
 */
class SinglyLinkedListPriorityQueue {
public:
    /**
     * Constructs a new, empty priority queue.
     */
    SinglyLinkedListPriorityQueue();

    /**
     * Deallocates all memory allocated by this priority queue.
     */
    ~SinglyLinkedListPriorityQueue();

    /**
     * Returns the number of elements stored in the priority queue.
     *
     * @return The number of elements stored in the priority queue.
     */
    int size() const;

    /**
     * Returns whether the queue is empty.
     *
     * @return Whether the queue is empty.
     */
    bool isEmpty() const;

    /**
     * Adds a new element to the priority queue.
     *
     * @param value The element to add
     */
    void enqueue(const std::string& value);

    /**
     * Returns, but does not remove, the lexicographically first string in
     * the priority queue. Equivalently, returns the next string that would
     * be removed by a call to dequeue.
     * <p>
     * If the priority queue is empty, this function will raise an error.
     *
     * @return The next string that would be dequeued.
     * @throws ErrorException If the queue is empty.
     */
    std::string peek() const;

    /**
     * Returns and removes the lexicographically first string in the
     * priority queue.
     * <p>
     * If the priority queue is empty, this function will raise an error.
     *
     * @return The lexicographically first string in the queue.
     * @throws ErrorException If the queue is empty.
     */
    std::string dequeueMin();

private:
    int countElements() const;
    bool hasNext(PatientNode node) const;
    PatientNode parseStringValue(std::string &token,PatientNode node);
    PatientNode *firstnode;
    PatientNode createNode(const std::string &token) const;

};


#endif
