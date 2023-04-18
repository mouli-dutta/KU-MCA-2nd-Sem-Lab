#include <iostream>

class RadixSort
{
private:
    int size;
    int *arr;

    int getMax() {
        int max = arr[0];
        for(int i = 1; i < size; i++) 
            if(arr[i] > max) 
                max = arr[i];
        return max;
    }

    void countSort(int exp) {
        int output[size];
        int count[10] = {0};

        for(int i = 0; i < size; i++) 
            count[(arr[i]/exp) % 10]++;
        
        for(int i = 1; i < 10; i++)
            count[i] += count[i-1];
        
        for(int i = size-1; i >= 0; i--) {
            output[count[(arr[i]/exp) % 10] - 1] = arr[i];
            count[(arr[i]/exp) % 10]--;
        }

        for(int i = 0; i < size; i++)
            arr[i] = output[i];
    }

public:
    RadixSort(int n, int *a) {
        size = n;
        arr = a;
    }
    ~RadixSort() {
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

    void radixSort() {
        int max = getMax();
        for(int exp = 1; max/exp > 0; exp *= 10)
            countSort(exp);
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

    RadixSort s(size, arr);

    std::cout << "Your array: ";
    s.print();

    s.radixSort();

    std::cout << "Array after sorting: ";
    s.print();

    return 0;
}