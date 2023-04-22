#include <iostream>

using namespace std;

// Node class to represent a single node in the linked list
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

// Linked list class to manage the nodes
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

    void insertion_sort();

    void print();

    void clear_list();
};


// Main function to test the linked list implementation
int main() {
    LinkedList<int> intList;

    intList.insert_begin(5);
    intList.insert_begin(10);

    intList.print();
    cout << "Length = " << intList.getLen() << "\n";


    LinkedList<int> intList2;

    intList2.insert_begin(25);
    intList2.insert_end(15);
    intList2.insert_at(2, 1);

    intList2.print();
    cout << "Length = " << intList2.getLen() << "\n";

    intList.append(intList2);
    intList.print();
    cout << "Length = " << intList.getLen() << "\n";

    intList.insertion_sort();
    intList.print();
    cout << "Length = " << intList.getLen() << "\n";

    LinkedList<string> stringList;

    stringList.insert_begin("hello");
    stringList.insert_begin("world");
    stringList.insert_at("beautiful", 1);

    stringList.print();
    cout << "Length = " << stringList.getLen() << "\n";

    stringList.delete_front();

    stringList.print();
    cout << "Length = " << stringList.getLen() << "\n";

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
    prev->getNext()->setNext(curr->getNext());
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
void LinkedList<T>::insertion_sort()
{
    if(!head || !head->getNext()) {
        cout << "List is already sorted.\n";
        return;
    }

    Node<T> *sortedList = nullptr;
    Node<T> *current = head;

    while(current) {
        Node<T> *nextNode = current->getNext();

        if(!sortedList || current->getData() < sortedList->getData()) {
            current->setNext(sortedList);
            sortedList = current;

        } else {
            Node<T> *temp = sortedList;
            while(temp) {
                if(!temp->getNext() || current->getData() < temp->getNext()->getData()) {
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
