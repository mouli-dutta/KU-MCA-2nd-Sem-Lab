#include <iostream>

const int SIZE = 5;

class Stack {
private:
    int top;
    int stk[SIZE];

    int isEmpty() {
        return top == -1;
    }

    int isFull() {
        return top == SIZE-1;
    }

public:
    // constructor
    Stack() {
        top = -1;
    }

    // destructor
    ~Stack() {}

    // pushes one element onto the stack
    void push(int data) {
        if(isFull())
            std::cout << "Stack Overflow\n";
        else {
            top++;
            stk[top] = data;
            std::cout << "Pushed " << data << " onto stack.\n";
        }
    }

    // removes one element from the top of the stack
    void pop() {
        if(isEmpty())
            std::cout << "Stack underflow\n";

        else {
            std::cout << "Poped: " << stk[top] << "\n";
            top--;
        }
    }

    // display the stack
    void display() {
        if(!isEmpty()) {
            std::cout << "Stack elements are:\n";
            for(int i = top; i >= 0; i--)
                std::cout << stk[i] << "\n";
        }

        else
            std::cout << "Stack is Empty\n";

    }
};

int main()
{
    Stack obj;

    std::cout << "\tMenu:\n"
              << "1. Push\n"
              << "2. Pop\n"
              << "3. Display\n"
              << "4. Exit\n";

    while(1) {
        int choice;
        std::cout << "Enter your choice between 1 to 4.\n";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter the data\n";
                int data;
                std::cin >> data;
                obj.push(data);

                break;

            case 2:
                obj.pop();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                exit(0);
                break;

            default:
                std::cout << "Invalid choice.\nPlease enter a number between 1 to 4.\n";
                break;

        }
    }

    return 0;
}
