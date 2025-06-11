#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &arr, int i) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key,
    // to one position ahead of their current position
    while(j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

void recursiveInsertionSort(vector<int> &arr, int n) {
    // Base case
    if(n <= 1) return;

    // Sort first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert last element at its correct position
    insert(arr, n - 1);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array:\n";
    for(int num : arr) cout << num << " ";
    cout << endl;

    recursiveInsertionSort(arr, arr.size());

    cout << "Sorted array:\n";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
