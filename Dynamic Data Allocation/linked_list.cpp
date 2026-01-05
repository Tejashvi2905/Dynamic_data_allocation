#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Base Class: Dynamic Memory Allocation (Linked List)
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted: " << data << endl;
    }

    // Display Linked List
    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search Operation
    void search(int key) {
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element " << key << " not found!" << endl;
    }

    // Delete Node by Value
    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Deleted: " << key << endl;
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted: " << key << endl;
    }

    // Reverse Linked List
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
        cout << "Linked List Reversed!" << endl;
    }
};

// Main Function
int main() {
    LinkedList list;

    list.insert_at_beginning(10);
    list.insert_at_beginning(20);
    list.insert_at_beginning(30);

    list.display();

    list.search(20);
    list.delete_node(10);

    list.display();

    list.reverse();
    list.display();

    return 0;
}
