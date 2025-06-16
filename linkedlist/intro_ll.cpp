#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=NULL;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout << "Underflow!";
            return;
        }
        else{
            Node* temp = head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "Underflow!" << endl;
            return;
        }

        // Only one node in the list
        if (head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        // More than one node
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }

        void insert_middle(int val, int pos){
        if(pos < 0){
            cout << "Invalid position" << endl;
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL){
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }

        if(temp == NULL){
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // Update tail if new node was inserted at the end
        if(newNode->next == NULL){
            tail = newNode;
        }
    }

    int search(int val){
        Node* temp=head;
        int i=0;
        while(temp!=NULL){
            temp=temp->next;
            i++;
            if(temp->data==val) return i;
        }
        return -1;
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);

    ll.printLL();
    ll.pop_front();
    ll.printLL();
    ll.pop_back();
    ll.printLL();

    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.insert_middle(9,2);
    ll.insert_middle(10,0);
    ll.printLL();
    ll.insert_middle(-1,-1);
    ll.insert_middle(9,9);
    ll.printLL();
    cout << ll.search(3);

    return 0;
}