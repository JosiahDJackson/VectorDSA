#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // For std::sort and std::binary_search

// Custom exception class
class myVectorException : public std::exception {
public:
    explicit myVectorException(const char* message) : std::exception(message) {}
};

template <class T>
class myVector : public std::vector<T> {
private:
    bool sorted;

public:
    myVector() : sorted(false) {}

    int seqSearch(T searchItem);
    int binarySearch(T searchItem);
    void bubbleSort();
    void insertionSort();
};

template <class T>
int myVector<T>::seqSearch(T searchItem) {
    for (int i = 0; i < this->size(); ++i) {
        if (this->at(i) == searchItem) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

template <class T>
void myVector<T>::bubbleSort() {
    for (int i = 0; i < this->size() - 1; ++i) {
        for (int j = 0; j < this->size() - i - 1; ++j) {
            if (this->at(j) > this->at(j + 1)) {
                // Swap elements if they are in the wrong order
                std::swap(this->at(j), this->at(j + 1));
            }
        }
    }
    sorted = true;
}

template <class T>
void myVector<T>::insertionSort() {
    for (int i = 1; i < this->size(); ++i) {
        T key = this->at(i);
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && this->at(j) > key) {
            this->at(j + 1) = this->at(j);
            j = j - 1;
        }
        this->at(j + 1) = key;
    }
    sorted = true;
}

template <class T>
int myVector<T>::binarySearch(T searchItem) {
    if (!sorted) {
        // Sort the vector if not already sorted
        std::sort(this->begin(), this->end());
        sorted = true;
    }

    int left = 0, right = this->size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if searchItem is present at mid
        if (this->at(mid) == searchItem)
            return mid;

        // If searchItem greater, ignore the left half
        if (this->at(mid) < searchItem)
            left = mid + 1;

        // If searchItem is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If we reach here, then the element was not present
    return -1;
}