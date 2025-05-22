/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1; // Pointer for next unique element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            ++k;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}