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

    void insert(Node** node, std::string word, int line);

    void singRotateLeft(Node** node);

    void singleRotateRight(Node** node);

    void doubleRotateLeft(Node** node);

    void doubleRotateRight(Node** node);

    int height(Node* node);

    int max(int a, int b);

    int compareWords(std::string str1, std::string str2);

    void printHelper(Node** node);

public:

    WordsAVL(std::string filePath);

    void print();

};


#endif //DOUBLYLINKEDLIST_WORDSAVL_H
