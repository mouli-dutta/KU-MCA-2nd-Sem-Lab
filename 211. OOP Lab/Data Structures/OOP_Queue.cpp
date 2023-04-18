#include <iostream>

const int SIZE = 5;

class Queue {
private:
    int front, rear;
    int queue[SIZE];

    int isFull() {
        return rear == SIZE -1;
    }

    int isEmpty() {
        return front == -1 || front > rear;
    }

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enQueue(int data) {
        if(isFull())
            std::cout << "Queue overflow\n";
        else {
            // if queue is initially empty
            if(front == -1)
                front = 0;

            queue[++rear] = data;
            //if(front > 0) front--;
            std::cout << "EnQueued " << data << "\n";
        }

        //std::cout << "EnQueue[REAR = " << rear << ", " << "Front = " << front << "]\n";
    }

    void deQueue() {
        if(isEmpty())
            std::cout << "Queue underflow\n";
        else {
            std::cout << "DeQueued " << queue[front] << "\n";
            front++;
            // rear--;

            // only happens when the last element is dequeued
            if(front > rear) {
                front = -1;
                rear = -1;
            }
        }

        //std::cout << "DeQueue[REAR = " << rear << ", " << "Front = " << front << "]\n";

    }

    void display() {
        if(!isEmpty()) {
            std::cout << "The Queue elements are:\n";
            for(int i = front; i <= rear; i++)
                std::cout << queue[i] << "\n";

        } else {
            std::cout << "Queue is empty\n";
        }

        //std::cout << "Display[REAR = " << rear << ", " << "Front = " << front << "]\n";
    }

};

int main()
{
    Queue obj;
    std::cout << "\tMenu:\n"
              << "1. EnQueue\n"
              << "2. DeQueue\n"
              << "3. Display\n"
              << "4. Exit\n";

    while(1) {
        std::cout << "Enter your choice between 1 to 4.\n";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter the data.\n";
                int data;
                std::cin >> data;
                obj.enQueue(data);
                break;

            case 2:
                obj.deQueue();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                std::cout << "Terminating the program.\n";
                exit(0);
                break;
        }
    }

    return 0;
}
