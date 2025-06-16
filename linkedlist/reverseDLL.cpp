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

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "Error: Underflow!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // list became empty
        }

        delete temp;
    }

    void pop_back() {
        if (tail == NULL) {
            cout << "Error: Underflow!" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL; // list became empty
        }

        delete temp;
    }

    void insert_at(int index, int val) {
        if (index == 0) {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp == tail) {
            push_back(val);
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void delete_at(int index) {
        if (head == NULL) {
            cout << "Error: Underflow!" << endl;
            return;
        }

        if (index == 0) {
            pop_front();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Error: Index out of bounds!" << endl;
            return;
        }

        if (temp == tail) {
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void reverse() {
        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);
    dll.push_back(50);

    cout << "Original List:\n";
    dll.print();

    dll.reverse();

    cout << "Reversed List:\n";
    dll.print();

    return 0;
}
