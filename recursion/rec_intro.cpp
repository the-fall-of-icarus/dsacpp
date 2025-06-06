#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printNum(int n){
    if(n==0){
        cout << n << endl;
        return;
    }
    else{
        cout << n << endl;
        printNum(n-1);
    }
}

void printName(int n, string name) {
    if (n == 0) return;
    cout << name << " ";
    printName(n - 1, name);
}

int sum(int n){
    if (n==0) return 0;
    else{
        return n+sum(n-1);
    }
}

int fact(int n){
    if(n==1){
        cout << endl;
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

bool isArraySorted(vector<int> &arr, int n) {
    if (n == 1) return true;
    if (arr[n - 1] < arr[n - 2]) return false;
    return isArraySorted(arr, n - 1);
}


int main(){
    vector<int> a={1,2,4,5,7,8};
    /*
    printNum(4);
    printName(4, "Veda");
    cout << endl;
    cout << sum(5);
    cout << fact(5) << endl;
    */
    cout << isArraySorted(a,a.size());
    return 0;
}