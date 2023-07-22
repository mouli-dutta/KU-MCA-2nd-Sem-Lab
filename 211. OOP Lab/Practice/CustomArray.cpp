#include <iostream>

using namespace std;

class MyArray {
private:
    int size;
    int *arr;

public:
    MyArray(int n) {
        size = n;
		arr = new int[n];
    }

    ~MyArray(){
		delete arr;
    }

    void takeArrInp(){
        for(int i = 0; i < size; i++){
	    	cout << "Enter the element at pos " << i << "\n";
	    	int data;
	    	cin >> data;
	    	arr[i] = data;
		}
    }

    void sortArr(){
	for(int i = 0; i < size; i++) {
	    for(int j = i; j < size; j++){
			if(arr[j] < arr[i]){
		    	int temp = arr[j];
				arr[j] = arr[i];
		    	arr[i] = temp;
			}
	    }
	}
    }

    void display(){
        for(int i = 0; i < size; i++)
	    cout << arr[i] << ", ";
	cout << "\n";
    }

    void search(int key) {
        int found = 0;
	for(int i = 0; i < size; i++) {
	    if(arr[i] == key) {
		cout << key << " is found at position "<< i << "\n";
	   	found = 1;
	     }
	}
	if(!found)
	    cout << key << " is not found\n";
    }

    void reverse(){
        int i = 0;
		int j = size-1;
		while(i < j) {
	    	int temp = arr[i];
	    	arr[i++] = arr[j];
	    	arr[j--] = temp;
		}
     }
};

int main() {
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    MyArray arr(n);
    arr.takeArrInp();
 

    cout << "\n\nMenu\n"
	 << "1. Sort\n"
	 << "2. Search\n"
	 << "3. Reverse\n"
	 << "4. Display\n"
	 << "5. Exit\n";

    while(1) {

        int choice;
        cout<<"Enter your choice between 1 to 5\n";
	cin >> choice;

        switch(choice) {
   	    case 1:
	        cout << "Sorting the array\n";
	        arr.sortArr();
	        break;
	    case 2:
	        cout << "Enter the element you want to search\n";
	        int target;
 	        cin >> target;
	        arr.search(target);
	        break;

	    case 3:
	        cout << "Your array is reversed.\n";
	        arr.reverse();
		break;
            case 4:
	        cout << "Your array\n";
	        arr.display();
	        break;

	    case 5:
	        cout << "Terminating the program\n";
	        exit(0);
	        break;
   	 }
    }

    return 0;
}









