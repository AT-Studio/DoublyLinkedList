//
// Created by athieler on 3/10/20.
//

#ifndef DOUBLYLINKEDLIST_WORDSAVL_H
#define DOUBLYLINKEDLIST_WORDSAVL_H


#include <string>
#include "DoublyLinkedList.h"

class WordsAVL {

    struct Node {
        std::string word;
        DoublyLinkedList* lines;
        Node* leftChild;
        Node* rightChild;
        int height;
    };

private:
    Node* root;

    static void insert(Node** node, std::string* word, int line);

    static void singRotateLeft(Node** node);

    static void singleRotateRight(Node** node);

    static void doubleRotateLeft(Node** node);

    static void doubleRotateRight(Node** node);

    static int height(Node* node);

    static int max(int a, int b);

    static int compareWords(std::string str1, std::string str2);

    static void printHelper(Node** node);

public:

    explicit WordsAVL(std::string* filePath);

    void print();

};


#endif //DOUBLYLINKEDLIST_WORDSAVL_H
