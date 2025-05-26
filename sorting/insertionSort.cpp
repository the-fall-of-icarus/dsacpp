#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a, int n){
    for(int i=0; i<n; i++){
        int curr = a[i];
        int prev = i-1;

        while(prev>=0 && a[prev]>curr){
            a[prev+1]=a[prev]; //shifting
            prev--;
        }
        a[prev+1]=curr; //placing the current element in it's correct position
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    int n=5;
    vector<int>arr={4,21,5,2,3};

    cout<<"the array: ";
    printArray(arr);

    insertionSort(arr, arr.size());

    cout<<"the array after sorting: ";
    printArray(arr);
    cout<<endl;

    return 0;
}