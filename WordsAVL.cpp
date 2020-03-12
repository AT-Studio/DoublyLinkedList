//
// Created by athieler on 3/10/20.
//

/**
 * @author Alexander Thieler
 * @description This program accepts a file path and then proceeds to parse the file for words. These words are then inserted
 * into a AVL tree along with the line number in which the word occurred. The order of the words in the tree is
 * alphabetical with lowercase being smaller than upper case lexicographically. The tree's contents can be printed
 * in order by using the print() function.
 */

#include "WordsAVL.h"
#include <fstream>
#include <iostream>
#include <iomanip>

/**
 * Constructor for WordsAVL. Sets the root to null and then parses the provided fill and inserts nodes as appropriate
 * @param filePath The file to be parsed
 */
WordsAVL::WordsAVL(std::string* filePath) {
    root = nullptr;

    std::ifstream inFile;
    inFile.open(*filePath);

    if (inFile) {
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
                insert(&root, &word, lineNumber);
            }
        }
    }
}

/**
 * Inserts a new node into the AVL tree
 * @param node The node that input string is checking against
 * @param word The word that is to be added to the tree
 * @param line The line on which the word to be inserted is located
 */
void WordsAVL::insert(Node** node, std::string* word, int line) {
    if (*node == nullptr) {
        *node = new Node();
        (*node)->leftChild = nullptr;
        (*node)->rightChild = nullptr;
        (*node)->word = *word;
        (*node)->lines = new DoublyLinkedList();
        (*node)->lines->insert_rear(line);
    } else if (compareWords(*word, (*node)->word) == 0) {
        if (!(*node)->lines->contains(line)) (*node)->lines->insert_rear(line);
    } else if (compareWords(*word, (*node)->word) < 0) {
        insert(&(*node)->leftChild, word, line);
        if (height((*node)->leftChild) - height((*node)->rightChild) == 2) {
            if (compareWords(*word, (*node)->leftChild->word) < 0) singleRotateRight(node);
            else doubleRotateRight(node);
        } else {
            (*node)->height = max(height((*node)->leftChild), height((*node)->rightChild)) + 1;
        }
    } else {
        insert(&(*node)->rightChild, word, line);
        if (height((*node)->rightChild) - height((*node)->leftChild) == 2) {
            if (compareWords(*word, (*node)->rightChild->word) > 0) {
                singRotateLeft(node);
            }
            else doubleRotateLeft(node);
        } else {
            (*node)->height = max(height((*node)->leftChild), height((*node)->rightChild)) + 1;
        }
    }
}

/**
 * Does a single rotation to the left
 * @param node The node on which the rotation is to take place
 */
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

/**
 * Does a single rotation to the right
 * @param node The node on which the rotation is to take place
 */
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

/**
 * Does a double rotation to the left (single rotation to the right followed by single rotation to the left)
 * @param node The node on which the double rotation is to take place
 */
void WordsAVL::doubleRotateLeft(WordsAVL::Node **node) {
    singleRotateRight(&((*node)->rightChild));
    singRotateLeft(node);
}

/**
 * Does a double rotation to the right (single rotation to the left followed by single rotation to the right)
 * @param node The node on which the double rotation is to take place
 */
void WordsAVL::doubleRotateRight(WordsAVL::Node **node) {
    singRotateLeft(&((*node)->leftChild));
    singleRotateRight(node);
}

/**
 * Returns the height of the node or -1 when null
 * @param node The node who's height is returned
 * @return The height of the provided node or -1
 */
int WordsAVL::height(WordsAVL::Node *node) {
    if (node != nullptr) return node->height;
    else return -1;
}

/**
 * Helper method to calculate the maximum of two integers
 * @param a Integer a
 * @param b Integer b
 * @return The maximum of a or b
 */
int WordsAVL::max(int a, int b) {
    return (a < b) ? b : a;
}

/**
 * Compares two strings and returns int based on their relative size in alphabetical order with lowercase followed by uppercase
 * @param str1 The first string to be compared
 * @param str2 The second string to be compared
 * @return An integer representing their relative size
 */
int WordsAVL::compareWords(std::string str1, std::string str2) {
    if (str1 == str2) return 0;
    else if ((isupper(str1[0]) && isupper(str2[0])) ||
            (islower(str1[0]) && islower(str2[0]))) return str1.compare(str2);
    else if (tolower(str1[0] == tolower(str2[0]))) return str2.compare(str1);
    else {
        std::string str1Copy = str1;
        str1Copy[0] = tolower(str1Copy[0]);

        std::string str2Copy = str2;
        str2Copy[0] = tolower(str2Copy[0]);

        return str1Copy.compare(str2Copy);
    }
}

/**
 * Public method exposed to allow users of the tree to print it's contents in order
 */
void WordsAVL::print() {
    printHelper(&root);
}

/**
 * Helper method that helps print the contents of the tree in order
 * @param node The current node that is to be printed in order
 */
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