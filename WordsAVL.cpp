//
// Created by athieler on 3/10/20.
//

#include "WordsAVL.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

WordsAVL::WordsAVL(std::string filePath) {
    root = nullptr;

    std::ifstream inFile;
    inFile.open(filePath);

    int lineNumber = 0;
    std::string line;
    while (std::getline(inFile, line)) {
        lineNumber++;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            for (auto c : word) {
                if (ispunct(c) && c != '\'') {
                    word.erase(word.find_first_of(c));
                }
            }
            insert(&root, word, lineNumber);
        }
    }
}

void WordsAVL::insert(Node** node, std::string word, int line) {

    if (*node == nullptr) {
        *node = new Node();
        (*node)->leftChild = nullptr;
        (*node)->rightChild = nullptr;
        (*node)->word = word;
        (*node)->lines = new DoublyLinkedList();
        (*node)->lines->insert_rear(line);
    } else if (compareWords(word, (*node)->word) == 0) {
        if (!(*node)->lines->contains(line)) (*node)->lines->insert_rear(line);
    } else if (compareWords(word, (*node)->word) < 0) {
        insert(&(*node)->leftChild, word, line);
        if (height((*node)->leftChild) - height((*node)->rightChild) == 2) {
            if (compareWords(word, (*node)->leftChild->word) < 0) singleRotateRight(node);
            else doubleRotateRight(node);
        } else {
            (*node)->height = max(height((*node)->leftChild), height((*node)->rightChild)) + 1;
        }
    } else {
        insert(&(*node)->rightChild, word, line);
        if (height((*node)->rightChild) - height((*node)->leftChild) == 2) {
            if (compareWords(word, (*node)->rightChild->word) > 0) {
                singRotateLeft(node);
            }
            else doubleRotateLeft(node);
        } else {
            (*node)->height = max(height((*node)->leftChild), height((*node)->rightChild)) + 1;
        }
    }
}

void WordsAVL::singRotateLeft(WordsAVL::Node **node) {
    Node *k1, *k2;
    k1 = *node;
    k2 = k1->rightChild;

    k1->rightChild = k2->leftChild;
    k2->leftChild = k1;

    k1->height = max(height(k1->leftChild), height(k1->rightChild)) + 1;
    k2->height = max(height(k2->rightChild), k1->height) + 1;

    *node = k2;
}

void WordsAVL::singleRotateRight(WordsAVL::Node **node) {
    Node *k1, *k2;
    k2 = *node;
    k1 = k2->leftChild;

    k2->leftChild = k1->rightChild;
    k1->rightChild = k2;

    k2->height = max(height(k2->leftChild), height(k2->rightChild)) + 1;
    k1->height = max(height(k1->leftChild), k2->height) + 1;

    *node = k1;
}

void WordsAVL::doubleRotateLeft(WordsAVL::Node **node) {
    singleRotateRight(&((*node)->rightChild));
    singRotateLeft(node);
}

void WordsAVL::doubleRotateRight(WordsAVL::Node **node) {
    singRotateLeft(&((*node)->leftChild));
    singleRotateRight(node);
}

int WordsAVL::height(WordsAVL::Node *node) {
    if (node != nullptr) return node->height;
    else return -1;
}

int WordsAVL::max(int a, int b) {
    return (a < b) ? b : a;
}

int WordsAVL::compareWords(std::string str1, std::string str2) {
    if (str1 == str2) return 0;
    else if (isupper(str1[0]) && isupper(str2[0])) return str1.compare(str2);
    else if (islower(str1[0]) && islower(str2[0])) return str1.compare(str2);
    else if (tolower(str1[0] == tolower(str2[0]))) return str2.compare(str1);
    else {
        std::string str1Copy = str1;
        str1Copy[0] = tolower(str1Copy[0]);

        std::string str2Copy = str2;
        str2Copy[0] = tolower(str2Copy[0]);

        return str1Copy.compare(str2Copy);
    }
}

void WordsAVL::print() {
    printHelper(&root);
}

void WordsAVL::printHelper(WordsAVL::Node **node) {
    if ((*node) == nullptr) return;
    printHelper(&(*node)->leftChild);
    std::string linesOutput;
    DoublyLinkedList* linesCopy = (*node)->lines->copy();
    bool hasAddedLine = false;
    for (int i = linesCopy->remove_front_i(); i != 0; i = linesCopy->remove_front_i()) {
        if (hasAddedLine) linesOutput.append(", ");
        hasAddedLine = true;
        linesOutput.append(std::to_string(i));
    }
    std::cout << std::setw(30) << std::left << (*node)->word << std::setw(1000) << std::left << linesOutput << std::endl;
    delete linesCopy;
    printHelper(&(*node)->rightChild);
}