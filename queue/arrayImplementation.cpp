#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
        size = 0;
    }

    void push(int val) {
        if (size == capacity) {
            cout << "Queue overflow!" << endl;
            return;
        }

        if (isEmpty()) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % capacity;
        }

        arr[rearIndex] = val;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }

        if (frontIndex == rearIndex) {
            // Only one element was in the queue
            frontIndex = rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % capacity;
        }
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);  // Create a queue with capacity 5

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);  // Should print "Queue overflow!"

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    q.pop();  // Should print "Queue underflow!"
    return 0;
}
