#include <iostream>
#include <functional>
#include "headers/Set.h"

void printMenu() {
    std::cout << "\n=== Set Operations Tester ===\n";
    std::cout << "1. Add element to Set A\n";
    std::cout << "2. Remove element from Set A\n";
    std::cout << "3. Check if element exists in Set A\n";
    std::cout << "4. Print Set A\n";
    std::cout << "5. Perform union with Set B\n";
    std::cout << "6. Perform intersection with Set B\n";
    std::cout << "7. Perform difference (A - B)\n";
    std::cout << "8. Check if Set B is subset of A\n";
    std::cout << "9. Check if sets are equal\n";
    std::cout << "10. Map operation (square all elements)\n";
    std::cout << "11. Where operation (even numbers only)\n";
    std::cout << "12. Reduce operation (sum all elements)\n";
    std::cout << "13. Create Set B from string\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() {
    Set<int> setA;
    Set<int>* setB = nullptr;
    int choice, value;
    std::string input;
    
    do {
        printMenu();
        std::cin >> choice;
        
        try {
            switch(choice) {
                case 1: {
                    std::cout << "Enter value to add: ";
                    std::cin >> value;
                    setA.add(value);
                    std::cout << "Value added.\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter value to remove: ";
                    std::cin >> value;
                    setA.remove(value);
                    std::cout << "Value removed.\n";
                    break;
                }
                case 3: {
                    std::cout << "Enter value to check: ";
                    std::cin >> value;
                    std::cout << "Value " << value 
                              << (setA.find(value) ? " exists" : " doesn't exist") 
                              << " in set.\n";
                    break;
                }
                case 4: {
                    std::cout << "Set A contents: ";
                    setA.print();
                    break;
                }
                case 5: {
                    if(!setB) {
                        std::cout << "Set B not initialized!\n";
                        break;
                    }
                    Set<int>* unionSet = setA.unio(setB);
                    std::cout << "Union result: ";
                    unionSet->print();
                    delete unionSet;
                    break;
                }
                case 6: {
                    if(!setB) {
                        std::cout << "Set B not initialized!\n";
                        break;
                    }
                    Set<int>* intersectSet = setA.intersection(setB);
                    std::cout << "Intersection result: ";
                    intersectSet->print();
                    delete intersectSet;
                    break;
                }
                case 7: {
                    if(!setB) {
                        std::cout << "Set B not initialized!\n";
                        break;
                    }
                    Set<int>* diffSet = setA.differ(setB);
                    std::cout << "Difference (A - B) result: ";
                    diffSet->print();
                    delete diffSet;
                    break;
                }
                case 8: {
                    if(!setB) {
                        std::cout << "Set B not initialized!\n";
                        break;
                    }
                    std::cout << "Set B is " 
                              << (setA.has_set(setB) ? "" : "not ") 
                              << "a subset of Set A\n";
                    break;
                }
                case 9: {
                    if(!setB) {
                        std::cout << "Set B not initialized!\n";
                        break;
                    }
                    std::cout << "Sets are " 
                              << (setA.is_equal(setB) ? "equal" : "not equal") 
                              << "\n";
                    break;
                }
                case 10: {
                    Set<int>* mappedSet = setA.map([](int x) { return x * x; });
                    std::cout << "Mapped set (squared values): ";
                    mappedSet->print();
                    delete mappedSet;
                    break;
                }
                case 11: {
                    Set<int>* filteredSet = setA.where([](int x) { return x % 2 == 0; });
                    std::cout << "Filtered set (even values only): ";
                    filteredSet->print();
                    delete filteredSet;
                    break;
                }
                case 12: {
                    int sum = setA.reduce([](int a, int b) { return a + b; }, 0);
                    std::cout << "Sum of all elements: " << sum << "\n";
                    break;
                }
                case 13: {
                    std::cout << "Enter space-separated values for Set B: ";
                    std::cin.ignore();
                    std::getline(std::cin, input);
                    if(setB) delete setB;
                    setB = to_set<int>(input);
                    std::cout << "Set B created: ";
                    setB->print();
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

    if(setB) delete setB;
    return 0;
}