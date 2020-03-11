//
// Created by athieler on 1/22/20.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

class DoublyLinkedList {

    struct Node {
        void* data;
        Node* next;
        Node* previous;
    };

private:
    Node* front;
    Node* rear;

public:

    DoublyLinkedList();

    void insert_front(int data);

    void insert_front(void* data);

    void insert_rear(int data);

    void insert_rear(void* data);

    int remove_front_i();

    void* remove_front_p();

    int remove_rear_i();

    void* remove_rear_p();

    bool contains(int data);

    int empty();

    void print();

    DoublyLinkedList* copy();

};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
