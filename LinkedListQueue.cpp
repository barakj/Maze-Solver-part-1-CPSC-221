//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

/**
 * Constructor: initializing the root node of the linked list
 */
LinkedListQueue::LinkedListQueue() {
    head = NULL;
    tail = NULL;
    size = 0;

}

/**
 * Adds an element to the Queue linked list, from the end/tail (FIFO)
 * @param elem the data of the new node to be inserted into the queue
 */
void LinkedListQueue::add(MazeState *elem) {
    // TODO:  Implement this.
    if (head == NULL) {
        head = new node;
        head->data = elem;
        head->next = NULL;
        tail = head;
    } else {
        node *temp = new node;
        tail->next = temp;
        temp->data = elem;
        temp->next = NULL;
        tail = temp;
    }
    size++;
}

/**
 * Removes the front/head element from the linked list Queue
 * @returns the data of the removed element
 */
MazeState *LinkedListQueue::remove() {
    assert(!is_empty());
    node *temp = new node;
    MazeState *ret = head->data;
// TODO:  Implement this.
//if(is_empty())
    //return NULL;
//else
    temp = head->next;;
    delete head;
    head = temp;
    size--;
    return ret;


}

/**
 * Checks whether the linked list queue is empty or not
 * @returns true if empty and false if not
 */
bool LinkedListQueue::is_empty() {
    // TODO:  Implement this.
    return (size == 0);

}

/**
 * Deconstructor: removes all nodes from list
 */
LinkedListQueue::~LinkedListQueue() {

    // TODO:  Implement the destructor.  Be sure to delete everything.
    while (head != NULL)
        remove();
}

#endif

