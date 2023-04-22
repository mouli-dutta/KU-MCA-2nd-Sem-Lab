#include <iostream>

using namespace std;

//---------------------------------------------------------
// Node class to represent a single node in the linked list
//---------------------------------------------------------
template<typename T>
class Node {
private:
    T data; // Data stored in the node
    Node* next; // Pointer to the next node in the list

public:
    Node(T data);

    T getData();
    void setData(T data);

    Node* getNext();
    void setNext(Node* next);
};


// ---------------------------------------------------------
// Linked list class to manage the nodes
// ---------------------------------------------------------
template<typename T>
class LinkedList {
private:
    Node<T>* head; // Pointer to the first node in the list
    int len; // length of the linked list

public:
    LinkedList(); 
    ~LinkedList();

    Node<T>* getHead();
    void setHead(Node<T>* node);

    int getLen();
    void setLen(int length);

    void insert_begin(T value);
    void insert_at(T value, int index);
    void insert_end(T value);

    void delete_front();
    void delete_at(int index);
    void delete_end();

    void append(LinkedList<T> &another);

    void insertion_sort(bool (*compare)(T, T));

    bool isFound(T target, bool (*equals)(T, T));

    void reverse();

    void print();

    void clear_list();
};



// --------------------------------------------------------------

// for taking user input
int getInput(string promt) {
    cout << promt;
    int inp;
    cin >> inp;
    return inp;
}

// function used in insertion_sort method for sorting in ascending order
bool compare(int a, int b) {
    return a < b;
}

// function used in search method to check if two values are equal
bool equals(int a, int b) {
    return a == b;
}



// Main function to test the linked list implementation
int main() {
    cout << "\tMenu:\n"
         << "1. Insert node at beginning.\n"
         << "2. Insert node at index (index starts from 0).\n"
         << "3. Insert node at end.\n"
         << "4. Delete first node.\n"
         << "5. Delete node at index (index starts from 0)."
         << "6. Print length of the list.\n"
         << "7. Sort the list.\n"
         << "8. Search for data in the list.\n"
         << "9. Reverse the list.\n"
         << "10. Concate two lists.\n"
         << "11. Print the list.\n"
         << "12. Exit.\n\n";

    LinkedList<int> list;

    while(true) {
        int choice = getInput("Enter your choice.\n");

        switch (choice)
        {
        case 1:
            list.insert_begin(
                getInput("Enter the data you want to insert.\n")
            );
            cout << "Inserted.\n";
            break;
        
        case 2:
            list.insert_at(
                getInput("Enter the data.\n"),
                getInput("Enter the index.\n")
            );
            cout << "Inserted.\n";
            break;
        
        case 3:
            list.insert_end(
                getInput("Enter the data.\n")
            );
            cout << "Inserted.\n";
            break;
        
        case 4:
            list.delete_front();
            cout << "Deleted.\n";
            break;
        
        case 5:
            list.delete_at(
                getInput("Enter the index.\n")
            );
            cout << "Deleted.\n";
            break;
        
        case 6:
            list.delete_end();
            cout << "Deleted.\n";
            break;
        
        case 7:
            list.insertion_sort(compare);
            cout << "Sorted.\n";
            break;
        
        case 8:
            {
                int target = getInput("Enter the value you want to search.\n");
                if(list.isFound(target, equals)) 
                    cout << "Target found.\n";
                else
                    cout << "Target not found.\n";
            }

            break;
        
        case 9:
            list.reverse();
            cout << "Reversed.\n";
            break;
        
        // TODO: append another list
        case 10:
            
            break;
        
        case 11:
            cout << "Your list:\n";
            list.print();
            break;

        default:
            cout << "Terminating the program.\n";
            exit(0);
            break;
        }
    }

    return 0;
}









// --------------------------------------------------------------
// Constructor and member function definations for the Node class
// --------------------------------------------------------------

// Constructor to create a new node
template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

// Getter method for the data member
template <typename T>
T Node<T>::getData() {
    return data;
}

// Setter method for the data member
template <typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

// Getter method for the next member
template <typename T>
Node<T> *Node<T>::getNext() {
    return next;
}

// Setter method for the next member
template <typename T>
void Node<T>::setNext(Node *next) {
    this->next = next;
}




// -----------------------------------------------------------------------------
// constructor, destructor and member functions definitions for LinkedList class
// -----------------------------------------------------------------------------

// Constructor to create an empty list
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), len(0) {}

// Destructor to free the memory allocated for the list nodes
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear_list();
}

// Getter method for head member
template <typename T>
Node<T> *LinkedList<T>::getHead()
{
    return head;
}

// Setter method for head member
template <typename T>
void LinkedList<T>::setHead(Node<T> *node)
{
    head = node;
}

// Getter method for len member
template <typename T>
int LinkedList<T>::getLen()
{
    return len;
}

// Setter method for len member
template <typename T>
void LinkedList<T>::setLen(int length)
{
    len = length;
}

// Method to insert a new node at the beginning of the list
template <typename T>
void LinkedList<T>::insert_begin(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(head);
    head = newNode;
    len++;
}

// Method to insert a new node at given index of the list
template <typename T>
void LinkedList<T>::insert_at(T value, int index)
{
    if(index < 0 || index > len) {
        cout << "Invalid index\n";
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    if(index == 0) {
        newNode->setNext(head);
        head = newNode;
    
    } else {
        Node<T>* current = head;
        while(--index) 
            current = current->getNext();
    
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    len++;
}

// Method to insert a new node at the end of the list
template <typename T>
void LinkedList<T>::insert_end(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if(!head) {
        head = newNode;
    
    } else {
        Node<T> *current = head;
        while(current->getNext())
            current = current->getNext();
        
        current->setNext(newNode);
    } 

    len++;
}

// Method to delete a node from the front of the list
template <typename T>
void LinkedList<T>::delete_front()
{
    if(!head) {
        cout << "List is empty\n";
        return;
    } else {
        Node<T> *tmp = head;
        head = head->getNext();
        delete tmp;
    }
    len--;
}

// Method to delete a node from a given index of the list
template <typename T>
void LinkedList<T>::delete_at(int index)
{
    if (index < 0 || index >= len) {
        cout << "Invalid index";
        return;
    }
    if (index == 0) {
        delete_front();
    }
    
    Node<T> *curr = head;
    Node<T> *prev = nullptr;
    while (--index) {
        prev = curr;
        curr = curr->getNext();
    }
    prev->setNext(curr->getNext());
    delete curr;
    len--;
}

// Method to delete a node from the end of the list
template <typename T>
void LinkedList<T>::delete_end()
{
    if (!head) {
        cout << "List is empty\n";
        return;

    } else if (!head->getNext()) {
        delete head;
        head = nullptr;

    } else {
        Node<T> *current = head;
        while (current->getNext()->getNext()) {
            current = current->getNext();
        }
        delete current->getNext();
        current->setNext(nullptr);
    }
    len--;
}

// Method to concatanate two lists
template <typename T>
void LinkedList<T>::append(LinkedList<T> &another)
{
    if(!another.getHead()) return;
    
    if(!head) {
        head = another.getHead();
        len = another.getLen();
        return;
    }
    
    Node<T> *curr = head;
    while(curr->getNext())
        curr = curr->getNext();

    curr->setNext(another.getHead());

    // update len to combine length of the list
    len += another.getLen();

    // deallocated memomry for another list
    another.setHead(nullptr);
    another.setLen(0);
}


// Method to sort the list using Insertion sort algorithm
template <typename T>
void LinkedList<T>::insertion_sort(bool (*compare)(T, T))
{
    if(!head || !head->getNext()) {
        cout << "List is already sorted.\n";
        return;
    }

    Node<T> *sortedList = nullptr;
    Node<T> *current = head;

    while(current) {
        Node<T> *nextNode = current->getNext();

        if(!sortedList || compare(current->getData(), sortedList->getData())) {
            current->setNext(sortedList);
            sortedList = current;

        } else {
            Node<T> *temp = sortedList;
            while(temp) {
                if(!temp->getNext() || compare(current->getData(), temp->getNext()->getData())) {
                    current->setNext(temp->getNext());
                    temp->setNext(current);
                    break;
                }
                temp = temp->getNext();
            }
        }
        current = nextNode;
    }
    head = sortedList;
}

template <typename T>
bool LinkedList<T>::isFound(T target, bool (*equals)(T, T))
{
    bool found = false;
    Node<T> *curr = head;
    while(curr) {
        if(equals(curr->getData(), target)) {
            found = true;
            break;
        }
        curr = curr->getNext();
    }
    return found;
}

template <typename T>
void LinkedList<T>::reverse()
{
    if(!head) {
        cout << "List is empty.\n";
        return;
    }

    Node<T> *curr = head;
    Node<T> *prev = nullptr, *next = nullptr;

    while(curr) {
        next = curr->getNext();
        curr->setNext(prev);

        prev = curr;
        curr = next;
    }
    head = prev;
}

// Method to print the contents of the list
template <typename T>
void LinkedList<T>::print()
{
    Node<T>* current = head;
    while (current != NULL) {
        cout << current->getData() << " -> ";
        current = current->getNext();
    }
    cout << "NULL\n";
}

// Function to delete all nodes in the list and free the memory
template <typename T>
void LinkedList<T>::clear_list()
{
    Node<T>* current = head;
    while (current != NULL) {
        Node<T>* temp = current;
        current = current->getNext();
        delete temp;
    }
    head = NULL;
}
