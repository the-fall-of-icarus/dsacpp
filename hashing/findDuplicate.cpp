#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int val : nums) {
            if (s.find(val) != s.end()) {
                return val;
            } else {
                s.insert(val);
            }
        }
        return -1; // In case there's no duplicate (but the problem guarantees at least one)
    }
};

//approach 2 - Space Complexity - O(1)
 int findDuplicate_1(vector<int>& nums) {
      int slow=nums[0], fast=nums[0];
      do{
        slow=nums[slow];
        fast=nums[nums[fast]];
      } while(slow != fast);
      slow=nums[0];
      while(slow != fast){
        slow=nums[slow];
        fast=nums[fast];
      }
      return slow;
    }

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    int duplicate = sol.findDuplicate(nums);
    
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
