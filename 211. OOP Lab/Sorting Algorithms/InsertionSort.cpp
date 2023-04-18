#include <iostream>

class InsertionSort {
private:
    int size;
    int *arr;

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    InsertionSort(int n, int *a) {
        size = n;
        arr = a;
    }

    ~InsertionSort() {
        delete arr;
    }

    int getSize() {
        return size;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            std::cout << arr[i];
            if(i != size-1) std::cout << ", ";
        }
        std::cout << "\n";
    }

    void insertionSort() {
        for(int i = 1; i < size; i++) 
        {
            for(int j = i; j >= 1; j--)
                if(arr[j] < arr[j-1]) 
                    swap(&arr[j], &arr[j-1]);
                else break;
        }
    }

};


int main() {
    int size;
    std::cout << "Enter the size of the array\n";
    std::cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++) {
        std::cout << "Enter the element at pos " << i << "-> ";
        std::cin >> arr[i];
    }

    InsertionSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.insertionSort();

    std::cout << "Array after sorting: ";
    s.print();

    return 0;
}