#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout << "Error: Underflow!";
        }else{
            Node*temp = head;
            head=head->next;

            if(head!=NULL){
                head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(head==NULL){
            cout << "Error: Underflow!";
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }

    void insert_at(int index, int val){
        if (index < 0){
            cout << "Error: Invalid index\n";
            return;
        }

        if (index == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < index - 1){
            temp = temp->next;
            count++;
        }

        if (temp == NULL){
            cout << "Error: Index out of bounds\n";
            return;
        }

        if (temp->next == NULL){
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void delete_at(int index){
        if (index < 0 || head == NULL){
            cout << "Error: Invalid index or empty list\n";
            return;
        }

        if (index == 0){
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < index){
            temp = temp->next;
            count++;
        }

        if (temp == NULL){
            cout << "Error: Index out of bounds\n";
            return;
        }

        if (temp->next == NULL){
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " <=> " ;
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){

    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);
    dll.push_back(5);

    dll.insert_at(2, 99); // Insert 99 at index 2
    dll.delete_at(4);   

    dll.pop_front();
    dll.pop_back();

    dll.print();
    return 0;
}