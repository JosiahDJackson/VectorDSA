#include "myVector.h"

int main() {
    // Test vector of integers
    myVector<int> intVector;
    intVector.push_back(5);
    intVector.push_back(2);
    intVector.push_back(8);
    intVector.push_back(1);
    intVector.push_back(9);
    intVector.push_back(3);
    intVector.push_back(7);
    intVector.push_back(4);

    // Test sort methods for integer vector
    std::cout << "Unsorted integer vector: ";
    for (const auto& num : intVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    intVector.bubbleSort();

    std::cout << "Sorted integer vector: ";
    for (const auto& num : intVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int intIndex1 = intVector.seqSearch(2);
    int intIndex2 = intVector.binarySearch(7);

    std::cout << "\nIndex of '2' (Sequential Search): " << intIndex1 << std::endl;
    std::cout << "Index of '7' (Binary Search): " << intIndex2 << std::endl;

    // Test STL sort and binary_search for integer vector
    std::sort(intVector.begin(), intVector.end());
    bool found = std::binary_search(intVector.begin(), intVector.end(), 7);

    std::cout << "\nUsing STL sort and binary_search for integer vector:" << std::endl;
    std::cout << "Sorted integer vector: ";
    for (const auto& num : intVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Found '7': " << (found ? "Yes" : "No") << std::endl;

    // Test vector of doubles
    myVector<double> doubleVector;
    doubleVector.push_back(3.5);
    doubleVector.push_back(1.2);
    doubleVector.push_back(8.9);
    doubleVector.push_back(2.4);
    doubleVector.push_back(7.1);
    doubleVector.push_back(5.6);
    doubleVector.push_back(4.3);
    doubleVector.push_back(6.7);

    // Test sort methods for double vector
    std::cout << "\nUnsorted double vector: ";
    for (const auto& num : doubleVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    doubleVector.insertionSort();

    std::cout << "Sorted double vector: ";
    for (const auto& num : doubleVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int doubleIndex1 = doubleVector.seqSearch(1.2);
    int doubleIndex2 = doubleVector.binarySearch(5.6);

    std::cout << "\nIndex of '1.2' (Sequential Search): " << doubleIndex1 << std::endl;
    std::cout << "Index of '5.6' (Binary Search): " << doubleIndex2 << std::endl;

    // Test STL sort and binary_search for double vector
    std::sort(doubleVector.begin(), doubleVector.end());
    found = std::binary_search(doubleVector.begin(), doubleVector.end(), 5.6);

    std::cout << "\nUsing STL sort and binary_search for double vector:" << std::endl;
    std::cout << "Sorted double vector: ";
    for (const auto& num : doubleVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Found '5.6': " << (found ? "Yes" : "No") << std::endl;

    return 0;
}