#include <iostream>
#include <vector>
using namespace std;

// Selection Sort Function
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        // Assume the minimum is at position i
        int minIndex = i;

        // Find the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum with the current element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Print Array Function
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main Function
int main() {
    vector<int> arr = {29, 10, 14, 37, 13};

    cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
