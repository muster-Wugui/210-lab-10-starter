// COMSC-210 | Lab 17 | Xiao Zhang

#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node* next;
};

void output(Node* head);
Node* front(Node* head, float value);
Node* delnode(Node* head, int position);
Node* insnode(Node* head, float value, int position);
Node* del(Node* head);

int main() {
    Node* head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = front(head, tmp_val);  // add nodes to the front
    }

    // Output the linked list
    output(head);

    // Delete a node
    int entry;
    cout << "Which node to delete? ";
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    // Call delnode function
    head = delnode(head, entry);
    output(head);

    // Insert a new node
    cout << "After which node to insert 10000? ";
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = insnode(head, 10000, entry);
    output(head);

    // Delete the entire list
    head = del(head);
    output(head);

    return 0;
}

//Prints the linked list
void output(Node* head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

//adds a new node at the front of the list
Node* front(Node* head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// deletes a node at a specific position
Node* delnode(Node* head, int position) {
    if (!head || position < 1) return head;

    Node* current = head;
    if (position == 1) {  // special case for head
        head = current->next;
        delete current;
        return head;
    }

    Node* prev = nullptr;
    for (int i = 1; i < position && current; i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }

    return head;
}

//inserts a new node at a specific position
Node* insnode(Node* head, float value, int position) {
    Node* newNode = new Node;
    newNode->value = value;

    if (position == 1) {  // insert at head
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    Node* prev = nullptr;
    for (int i = 1; i < position && current; i++) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        newNode->next = current;
        prev->next = newNode;
    }

    return head;
}

//deletes the entire linked list
Node* del(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return nullptr;
}
