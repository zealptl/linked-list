#include <iostream>

//class defines a node of a linked list
class Node {
public:
    int data;
    Node *next;
    Node(int data = 0);
};

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

//class defines linked list and its functions
class LinkedList {
public:
    Node *head, *tail;
    LinkedList();
    void insert(int data);
    void insertPos(int data, int pos);
    void deletePos(int pos);
    void print();
    int length();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

//creates a node and then inserts at the end of the list
void LinkedList::insert(int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

//creates a node and then inserts at a given position
void LinkedList::insertPos(int data, int pos) {
    Node *temp = new Node(data);
    Node *prev = new Node;
    Node *curr = new Node;
    curr = head;
    for (int i = 0; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
}

//deletes a node at a given pos
void LinkedList::deletePos(int pos) {
    Node *prev = new Node;
    Node *curr = new Node;
    Node *temp = new Node;
    curr = head;
    for (int i = 0; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }
    temp = curr;
    prev->next = curr->next;
}

//returns the length of a linked list
int LinkedList::length() {
    int length{};
    Node *temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

//prints all the nodes in a linked list separated by a space
void LinkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr= curr->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list; //creates a list
    list.insert(1); //inserts in the end of list
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    list.print(); //prints the list
    std::cout << "Length of the list: " << list.length() << std::endl;
    list.insertPos(4, 3); //inserts a node with data = 4 at index 3
    list.print();
    list.deletePos(4); //deletes the node at index 4
    list.print();
    return 0;
}
