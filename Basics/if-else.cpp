#include<bits/stdc++.h>
using namespace std;

int main(){

    int age;
    cin >> age;

    if(age<18){
        cout << "Not eligible for job";
    }

    else if (age>=18 && age<55) {
        cout << "Eligible for Job";
    }

    else if(55<=age && age<=57){
        cout << "Eligible for job but retirement soon.";
    }

    else{
        cout << "Retirement time!";
    }
    
    return 0;
}