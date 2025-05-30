#include <iostream>
#include <functional>
#include "headers/Heap.h"

void printHeapMenu() {
    std::cout << "\n=== Heap Tester ===\n";
    std::cout << "1. Add element\n";
    std::cout << "2. Remove top element\n";
    std::cout << "3. Get top element\n";
    std::cout << "4. Check if heap is empty\n";
    std::cout << "5. Print heap\n";
    std::cout << "6. Test subtree operations\n";
    std::cout << "7. Test traversal types\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() {
    Heap<int> heap;
    int choice, value;
    
    do {
        printHeapMenu();
        std::cin >> choice;
        
        try {
            switch(choice) {
                case 1: {
                    std::cout << "Enter value to add: ";
                    std::cin >> value;
                    heap.Add(value);
                    std::cout << "Value added to heap.\n";
                    break;
                }
                case 2: {
                    if (heap.Empty()) {
                        std::cout << "Heap is empty!\n";
                    } else {
                        heap.Remove();
                        std::cout << "Top element removed.\n";
                    }
                    break;
                }
                case 3: {
                    if (heap.Empty()) {
                        std::cout << "Heap is empty!\n";
                    } else {
                        std::cout << "Top element: " << heap.Top() << "\n";
                    }
                    break;
                }
                case 4: {
                    std::cout << "Heap is " << (heap.Empty() ? "empty" : "not empty") << "\n";
                    break;
                }
                case 5: {
                    std::cout << "Heap contents: ";
                    heap.Print();
                    std::cout << "\n";
                    break;
                }
                case 6: {
                    std::cout << "Enter value for subtree root: ";
                    std::cin >> value;
                    auto subtree = heap.Subtree(value);
                    if(!subtree->Empty()) {
                        std::cout << "Subtree contents: ";
                        subtree->Print();
                        
                        std::cout << "\nCheck if main heap contains this subtree: ";
                        std::cout << (heap.Hassubtree(subtree) ? "Yes" : "No") << "\n";
                        
                        delete subtree;
                    } else {
                        std::cout << "Value not found in heap.\n";
                    }
                    break;
                }
                case 7: {
                    std::cout << "NLR traversal: " << heap.Travel(NLR_) << "\n";
                    std::cout << "LNR traversal: " << heap.Travel(LNR_) << "\n";
                    std::cout << "LRN traversal: " << heap.Travel(LRN_) << "\n";
                    std::cout << "RNL traversal: " << heap.Travel(RNL_) << "\n";
                    std::cout << "NRL traversal: " << heap.Travel(NRL_) << "\n";
                    std::cout << "RLN traversal: " << heap.Travel(RLN_) << "\n";
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