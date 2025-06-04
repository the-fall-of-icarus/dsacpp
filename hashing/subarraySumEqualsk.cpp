#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute force approach
int subSum_bf(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

// Optimized approach using prefix sums and hashmap
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    m[0] = 1; // prefix sum 0 has occurred once
    int currSum = 0;
    int count = 0;

    for (int num : nums)
    {
        currSum += num;

        if (m.find(currSum - k) != m.end())
        {
            count += m[currSum - k];
        }

        m[currSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3, -2, 1, 2, 1};
    int k = 3;

    cout << "Brute Force Count: " << subSum_bf(nums, k) << endl;
    cout << "Optimized Count: " << subarraySum(nums, k) << endl;

    return 0;
}
