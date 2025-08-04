#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    cout << dq.front() << " " << dq.back() << endl;
    dq.push_back(4);
    dq.push_front(5);
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}