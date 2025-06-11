#include<iostream>
#include<vector>
using namespace std;

void recursiveBubbleSort(vector<int> &arr, int n) {
    // Base case: if the array has only one element or is already sorted
    if(n == 1) return;

    // One pass of bubble sort to move the largest to the end
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    // Recursive call on the remaining array
    recursiveBubbleSort(arr, n - 1);
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array:\n";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    recursiveBubbleSort(arr, arr.size());

    cout << "Sorted array:\n";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
