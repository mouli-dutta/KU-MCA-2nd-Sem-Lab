#include <iostream>

class QuickSort {
private:
    int size;
    int *arr;

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int a[], int first, int last) {
        int i = first + 1; // to swap values
        int pivot = first; // taking the first element as the pivot

        // loop from first value to last value
        while(first <= last) {
            // check if any element between first and last 
            // is lesser than pivot element
            if(a[first] < a[pivot]) 
                swap(&a[i++], &a[first]);  // if condition is true, then swap them  
            
            first++;
        }

        swap(&a[pivot], &a[i-1]); // swap pivot to proper index

        return (i-1); // return the index of the pivot
    }

public:
    QuickSort(int n, int *a) {
        size = n;
        arr = a;
    }

    ~QuickSort() {
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

    void quickSort(int first, int last) {
        if(first < last) 
        {
            int pivot = partition(arr, first, last); // index of the pivot
            quickSort(first, pivot-1); // sort the left side of the pivot element
            quickSort(pivot+1, last); // sort the right side of the pivot element
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

    QuickSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.quickSort(0, size-1);

    std::cout << "Array after sorting: ";
    s.print();


    return 0;
}