#include <iostream>
#include "DoublyLinkedList.h"
#include "WordsAVL.h"

int main() {
    auto* list = new DoublyLinkedList();

//    // List methods with empty list
//    int test0 = list->remove_front_i();
//    std::cout << "Expected 0 and returned " << test0 << std::endl;
//    void* test1 = list->remove_front_p();
//    if (test1 == nullptr) std::cout << "Expected null and returned null" << std::endl;
//    else std::cout << "Expected null and returned not null" << std::endl;
//    int test2 = list->remove_rear_i();
//    std::cout << "Expected 0 and returned " << test2 << std::endl;
//    void* test3 = list->remove_rear_p();
//    if (test3 == nullptr) std::cout << "Expected null and returned null" << std::endl;
//    else std::cout << "Expected null and returned not null" << std::endl;
//
//    //List methods with 1 element
//    list->insert_rear(3);
//    int test4 = list->remove_front_i();
//    std::cout << "Expected 3 and returned " << test4 << std::endl;
//    list->insert_front(3);
//    int test5 = list->remove_rear_i();
//    std::cout << "Expected 3 and returned " << test5 << std::endl;
//    int* p0 = new int(3);
//    list->insert_front(p0);
//    int* p0Test = (int*) list->remove_rear_p();
//    std::cout << "Expected 3 and returned " << *p0Test << std::endl;
//    delete p0;
//    int* p1 = new int(3);
//    list->insert_rear(p0);
//    int* p1Test = (int*) list->remove_front_p();
//    std::cout << "Expected 3 and returned " << *p1Test << std::endl;
//    delete p1;
//
//    //List methods with 2 elements
//    list->insert_front(3);
//    list->insert_rear(5);
//    int test6 = list->remove_front_i();
//    std::cout << "Expected 3 and returned " << test6 << std::endl;
//    list->insert_front(7);
//    int test7 = list->remove_rear_i();
//    std::cout << "Expected 5 and returned " << test7 << std::endl;
//    list->empty();
//
//
//    //Test empty
//    list->insert_front(4);
//    list->insert_front(6);
//    list->insert_front(8);
//    int test8 = list->empty();
//    std::cout << "Expected 3 and returned " << test8 << std::endl;
//    int test9 = list->remove_front_i();
//    std::cout << "Expected 0 and returned " << test9 << std::endl;

    auto* tree = new WordsAVL("../TextFile");
    tree->print();
//    DoublyLinkedList* lines = tree->getLinesForWord("rain");
//    std::cout << "line " << lines->remove_front_i() << std::endl;

    return 0;
}
