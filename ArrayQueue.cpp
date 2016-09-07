#ifndef _ARRAYQUEUESOLN_CPP
#define _ARRAYQUEUESOLN_CPP

//ArrayQueueSoln.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfMazeStates
/**
 * Constructor: initialize member variables and do any other initialization needed (if any)
 */
ArrayQueue::ArrayQueue() {
    // TODO: implement constructor
    tail = 0;
    head = 0;
    capacity = INIT_SIZE;
    array = new MazeState *[INIT_SIZE];
}

/**
 * Adds an element to the Array Queue, taking into consideration it is circular
 * @param elem a pointer to the MazeState element to be added to the queue.
 */
void ArrayQueue::add(MazeState *elem) {
    // TODO: implement add method
    //if the queue is full (circular array)
    if ((tail + 1) % (capacity) == head) {
        // ensure_capacity makes grows the array.
        ensure_capacity(capacity + 1);
    }
    //add the element at the end of the array (tail) - FIFO
    array[tail] = elem;
    //re-adjust the tail according to the new size
    tail = (tail + 1) % (capacity);
}

/**
 * Removes the front/head element from the Array Queue, taking into consideration it is circular
 * @returns the element that was removed
 */
MazeState *ArrayQueue::remove() {
    // TODO: implement remove method
    assert(!is_empty());
    //to be removed
    MazeState *temp = array[head];
    //adjust head since ciruclar array
    head = (head + 1) % (capacity);
    return temp;
}

/**
 * Checks whether the array queue is empty or not
 * @returns true if empty and false if not
 */
bool ArrayQueue::is_empty() {
    // TODO: implement is_empty method
    return (head == tail);
}

/**
 * ensure the array queue is big enough to contain all elements, if not it will grow the array
 * @param n the number of elements the array needs to be able to contain
 */
// TODO: implement ensure_capacity (but leave this to last.. just start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n) {
    if (capacity < n) {
        // Make plenty of room.
        int target_capacity = (n > 2 * capacity + 1) ? n : (2 * capacity + 1);
        // TODO: Set the current array aside and make room for the new one.
        MazeState **temp = array;
        MazeState **arraynew = new MazeState *[target_capacity];

        // Copy each element of the old array over.
        int i = 0;
        for (int count = 0; count < capacity; count++) {
            arraynew[count] = temp[count];
            i++;
            head++;
        }
        //once copied the whole old  normal array, check if there are any other elements the are found between tail and head (circular)

        if (tail < head) {
            for (int a = 0; a < tail; ++a) {
                arraynew[i] = temp[a];
                i++;
            }
        }
        // TODO: Fix front and back and capacity so they correspond to the new array.
        head = 0;
        tail = n - 1;
        array = arraynew;
        capacity = target_capacity;
        // TODO: Delete the old array.
        delete[] temp;
    }
}

/**
 * Deconstructor
 */
ArrayQueue::~ArrayQueue() {
    // TODO: implement the destructor
    delete[] array;
}

#endif
