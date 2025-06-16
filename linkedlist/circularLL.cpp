#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class CircularDoublyList {
    Node* head;

public:
    CircularDoublyList() {
        head = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;
    }

    void pop_front() {
        if (!head) {
            cout << "Error: Underflow!\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head->prev;
        Node* temp = head;

        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    void pop_back() {
        if (!head) {
            cout << "Error: Underflow!\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head->prev;
        Node* newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;

        delete tail;
    }

    void insert_at(int index, int val) {
        if (index < 0) {
            cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        int count = 0;

        while (count < index - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count < index - 1) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* newNode = new Node(val);
        Node* nextNode = temp->next;

        newNode->next = nextNode;
        newNode->prev = temp;

        temp->next = newNode;
        nextNode->prev = newNode;
    }

    void delete_at(int index) {
        if (!head || index < 0) {
            cout << "Invalid index or empty list\n";
            return;
        }

        if (index == 0) {
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 0;

        while (count < index && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count < index) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete temp;
    }

    void print() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " <=> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

int main() {
    CircularDoublyList cll;

    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cll.push_front(5);
    cll.print();

    cll.insert_at(2, 15); // Insert 15 at index 2
    cll.print();  
    cll.delete_at(1);     // Delete node at index 1
    cll.print(); 

    cll.pop_front();
    cll.print(); 
    cll.pop_back();

    cll.print(); // Final list

    return 0;
}
