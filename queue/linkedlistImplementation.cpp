#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = tail = newNode;
        } else {
            tail->next=newNode;
            tail=newNode;
            newNode->next=NULL;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "underflow!\n";
            return;
        } 
        Node* temp = head;
        head=head->next;
        delete temp;
    }

    int front(){
        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }
};

int main(){

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}