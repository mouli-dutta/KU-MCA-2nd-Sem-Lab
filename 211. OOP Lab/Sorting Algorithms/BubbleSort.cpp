#include <iostream>

class BubbleSort {
private:
    int size;
    int *arr;

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    BubbleSort(int n, int *a) {
        size = n;
        arr = a;
    }

    ~BubbleSort() {
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

    void bubbleSort() {
        for(int i = 0; i < size-1; i++) 
        {
            int swapped = 0;
            for(int j = 0; j < size-i-1; j++) 
            {
                if(arr[j] > arr[j+1]) 
                {
                    swap(&arr[j], &arr[j+1]);
                    swapped = 1;
                }
            }
            if(!swapped) break;
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

    BubbleSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.bubbleSort();

    std::cout << "Array after sorting: ";
    s.print();

    return 0;
}