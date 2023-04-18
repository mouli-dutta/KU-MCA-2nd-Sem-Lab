#include <iostream>

class MergeSort {
private:
    int size;
    int *arr;

    void mergeParts(int first, int middle, int last) {
        int n1 = middle - first + 1;
        int n2 = last - middle;

        int left[n1], right[n2];

        for(int i = 0; i < n1; i++) left[i] = arr[first+i];
        for(int i = 0; i < n2; i++) right[i] = arr[middle+1 + i];

        int lIdx = 0, rIdx = 0;

        for(int i = first; i <= last; i++) 
        {
            if(left[lIdx] <= right[rIdx])
                arr[first++] = left[lIdx++];
            else 
                arr[first++] = right[rIdx++];
        }
    }

public:
    MergeSort(int n, int *a) {
        size = n;
        arr = a;
    }

    ~MergeSort() {
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

    void mergeSort(int first, int last) {
        if(first < last) 
        {
            int middle = first + (last - first) / 2;
            mergeSort(first, middle); // sort the left side of the array
            mergeSort(middle+1, last); // sort the right side of the array
            mergeParts(first, middle, last); // merge both sides
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

    MergeSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.mergeSort(0, size-1);

    std::cout << "Array after sorting: ";
    s.print();

    return 0;
}