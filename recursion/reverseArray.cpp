/*
    Problem:
    Given an array of n elements, reverse the array in-place using recursion.

    Input: 
    n = 5, arr = [1, 2, 3, 4, 5]
    Output: [5, 4, 3, 2, 1]

    Approach:
    - Use two pointers (start and end).
    - Swap the elements at start and end.
    - Recur for the remaining array (start+1, end-1).
*/

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end) {
    if (start >= end) return; // base case
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1); // recursive call
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
