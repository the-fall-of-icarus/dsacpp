#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pivot = -1;
    int n = nums.size();

    // Step 1: Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Step 2: If no pivot, reverse the whole array
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find element just greater than pivot and swap
    for (int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 4: Reverse the suffix
    reverse(nums.begin() + pivot + 1, nums.end());
}

void printArray(const vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {1,2,3,6,5,4};  
    cout << "Original array: ";
    printArray(nums);

    nextPermutation(nums);

    cout << "Next permutation: ";
    printArray(nums);

    return 0;
}
