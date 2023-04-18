#include <iostream>

class SelectionSort {
private:
    int size;
    int *arr;

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    SelectionSort(int n, int *a) {
        size = n;
        arr = a;
    }

    ~SelectionSort() {
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

    void selectionSort() {
        for(int i = 0; i < size; i++)
        {
            int min = i;
            for(int j = i + 1; j < size; j++)
                if(arr[j] < arr[min]) 
                    min = j;

            swap(&arr[i], &arr[min]);
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

    SelectionSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.selectionSort();

    std::cout << "Array after sorting: ";
    s.print();

    return 0;
}