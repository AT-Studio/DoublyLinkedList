//
// Created by athieler on 1/22/20.
//

#include <iostream>
#include "DoublyLinkedList.h"

/**
 * Constructor of the list. Sets front and rear nodes to point to null by default
 */
DoublyLinkedList::DoublyLinkedList() {
    front = nullptr;
    rear = nullptr;
}

/**
 * Creates a new Node to be inserted into the front of the list
 * @param data - int value for node data
 */
void DoublyLinkedList::insert_front(int data) {
    Node* node = new Node();
    node->data = nullptr;
    node->data = (int*) data; //Stores the int value in the pointer memory location
    node->previous = nullptr;
    if (front == nullptr) {
        node->next = nullptr;
        rear = node;
    } else {
        node->next = front;
        front->previous = node;
    }
    front = node;
}

/**
 * Creates a new Node to be inserted into the front of the list
 * @param data - pointer to location of data in memory for node
 */
void DoublyLinkedList::insert_front(void *data) {
    Node* node = new Node();
    node->data = data;
    node->previous = nullptr;
    if (front == nullptr) {
        node->next = nullptr;
        rear = node;
    } else {
        node->next = front;
        front->previous = node;
    }
    front = node;
}

/**
 * Creates a new Node to be inserted into the rear of the list
 * @param data - int value for node data
 */
void DoublyLinkedList::insert_rear(int data) {
    Node* node = new Node();
    node->data = nullptr;
    node->data = (int*) data; //Stores the int value in the pointer memory location
    node->next = nullptr;
    if (rear == nullptr) {
        node->previous = nullptr;
        front = node;
    } else {
        node->previous = rear;
        rear->next = node;
    }
    rear = node;
}

/**
 * Creates a new Node to be inserted into the rear of the list
 * @param data - pointer to location of data in memory for node
 */
void DoublyLinkedList::insert_rear(void *data) {
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    if (rear == nullptr) {
        node->previous = nullptr;
        front = node;
    } else {
        node->previous = rear;
        rear->next = node;
    }
    rear = node;
}

/**
 * Removes the front Node from the list and returns its data as an int
 * @return int value of data
 */
int DoublyLinkedList::remove_front_i() {
    Node* oldFront = front;
    if (oldFront == nullptr) return 0;
    else if (oldFront->next == nullptr) {
        front = nullptr;
        rear = nullptr;
    } else {
        front = oldFront->next;
        front->previous = nullptr;
    }
    int val = reinterpret_cast<std::uintptr_t>(oldFront->data); // gets the int value stored in the pointer memory location
    delete oldFront;
    return val;
}

/**
 * Removes the front Node from the list and returns its data as a void pointer
 * @return void pointer to data
 */
void* DoublyLinkedList::remove_front_p() {
    Node* oldFront = front;
    if (oldFront == nullptr) return nullptr;
    else if (oldFront->next == nullptr) {
        front = nullptr;
        rear = nullptr;
    } else {
        front = oldFront->next;
        front->previous = nullptr;
    }
    void* data = oldFront->data;
    delete oldFront;
    return data;
}

/**
 * Removes the rear Node from the list and returns its data as an int
 * @return int value of data
 */
int DoublyLinkedList::remove_rear_i() {
    Node* oldRear = rear;
    if (oldRear == nullptr) return 0;
    else if (oldRear->previous == nullptr) {
        front = nullptr;
        rear = nullptr;
    } else {
        rear = oldRear->previous;
        rear->next = nullptr;
    }
    int val = reinterpret_cast<std::uintptr_t>(oldRear->data); // gets the int value stored in the pointer memory location
    delete oldRear;
    return val;
}

/**
 * Removes the rear Node from the list and returns its data as an int
 * @return void pointer to data
 */
void* DoublyLinkedList::remove_rear_p() {
    Node* oldRear = rear;
    if (oldRear == nullptr) return nullptr;
    else if (oldRear->previous == nullptr) {
        front = nullptr;
        rear = nullptr;
    } else {
        rear = oldRear->previous;
        rear->next = nullptr;
    }
    void* data = oldRear->data;
    delete oldRear;
    return data;
}

/**
 * Empties the current list by removed all nodes from the list
 * @return the number of nodes removed
 */
int DoublyLinkedList::empty() {
    int counter = 0;
    while (front != nullptr) {
        counter++;
        Node* oldFront = front;
        front = oldFront->next;
        delete oldFront;
    }
    rear = nullptr;
    return counter;
}