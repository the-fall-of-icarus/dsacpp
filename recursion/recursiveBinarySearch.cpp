#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search function
int binSearch(vector<int> &arr, int target, int start, int end) {
    if (start > end) return -1; // Base case: not found

    int mid = start + (end - start) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binSearch(arr, target, start, mid - 1);
    else return binSearch(arr, target, mid + 1, end);
}

int main() {
    vector<int> nums = {-10, -3, 0, 1, 3, 5, 7, 9, 12};
    int target = 5;

    int index = binSearch(nums, target, 0, nums.size() - 1);

    if (index != -1)
        cout << "Target " << target << " found at index: " << index << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
