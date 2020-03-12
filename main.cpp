#include <iostream>
#include "DoublyLinkedList.h"
#include "WordsAVL.h"

int main() {

    std::string filePath = "../TextFile";
    auto* tree = new WordsAVL(&filePath);
    tree->print();

    delete tree;

    return 0;
}
