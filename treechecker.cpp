#include <iostream>
#include <functional>
#include "headers/Tree.h"

void printMenu() {
    std::cout << "\n=== AVL Tree Tester ===\n";
    std::cout << "1. Insert element\n";
    std::cout << "2. Remove element\n";
    std::cout << "3. Check if element exists\n";
    std::cout << "4. Print tree (LNR traversal)\n";
    std::cout << "5. Clear tree\n";
    std::cout << "6. Test map/where/reduce\n";
    std::cout << "7. Test subtree operations\n";
    std::cout << "8. Test merge operation\n";
    std::cout << "9. Test traversal types\n";
    std::cout << "10. Test threading\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() {
    Tree<int> tree;
    int choice, value;
    
    do {
        printMenu();
        std::cin >> choice;
        
        try {
            switch(choice) {
                case 1: {
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    tree.insert(value);
                    std::cout << "Value inserted.\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter value to remove: ";
                    std::cin >> value;
                    tree.remove(value);
                    std::cout << "Value removed.\n";
                    break;
                }
                case 3: {
                    std::cout << "Enter value to check: ";
                    std::cin >> value;
                    std::cout << "Value " << value 
                              << (tree.contains(value) ? " exists" : " doesn't exist") 
                              << " in tree.\n";
                    break;
                }
                case 4: {
                    std::cout << "Tree contents (LNR): ";
                    tree.print();
                    break;
                }
                case 5: {
                    tree.clear();
                    std::cout << "Tree cleared.\n";
                    break;
                }
                case 6: {
                    auto doubleTree = tree.map([](int x) { return x * 2; });
                    std::cout << "Mapped tree (values doubled): ";
                    doubleTree->print();
                    delete doubleTree;

                    auto evenTree = tree.where([](int x) { return x % 2 == 0; });
                    std::cout << "Filtered tree (even values only): ";
                    evenTree->print();
                    delete evenTree;

                    int sum = tree.reduce([](int a, int b) { return a + b; }, 0);
                    std::cout << "Sum of all elements: " << sum << "\n";
                    break;
                }
                case 7: {
                    std::cout << "Enter value for subtree root: ";
                    std::cin >> value;
                    auto subtree = tree.subtree(value);
                    if(subtree) {
                        std::cout << "Subtree contents: ";
                        subtree->print();
                        delete subtree;
                    } else {
                        std::cout << "Value not found in tree.\n";
                    }
                    break;
                }
                case 8: {
                    Tree<int> otherTree;
                    std::cout << "How many values to insert in second tree? ";
                    int count;
                    std::cin >> count;
                    for(int i = 0; i < count; i++) {
                        std::cout << "Enter value " << i+1 << ": ";
                        std::cin >> value;
                        otherTree.insert(value);
                    }
                    tree.merge(&otherTree);
                    std::cout << "Trees merged. Current tree contents: ";
                    tree.print();
                    break;
                }
                case 9: {
                    std::cout << "NLR traversal: " << tree.travel(NLR) << "\n";
                    std::cout << "LNR traversal: " << tree.travel(LNR) << "\n";
                    std::cout << "LRN traversal: " << tree.travel(LRN) << "\n";
                    std::cout << "RLN traversal: " << tree.travel(RLN) << "\n";
                    std::cout << "RNL traversal: " << tree.travel(RNL) << "\n";
                    std::cout << "RLN traversal: " << tree.travel(RLN) << "\n";
                    std::cout << "Level-order traversal: \n" << tree.travel(LAYOT) << "\n";
                    break;
                }
                case 10: {
                    tree.thread(LNR);
                    std::cout << "Threaded tree (LNR order): ";
                    tree.printFromThread();
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Invalid option!\n";
                }
            }
        } catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    } while(choice != 0);

    return 0;
}