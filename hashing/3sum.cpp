#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// brute force appraoch - gives TLE on Leetcode
vector<vector<int>> threeSum_bf(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s; // to store unique triplets
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    if (s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

// appraoch 2 - better but still gives TLE => HASHING APPROACH
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    int target, toFind;
    for (int i = 0; i < n; i++)
    {
        target = -nums[i];
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            toFind = target - nums[j];
            if (s.find(toFind) != s.end())
            {
                vector<int> triplet = {nums[i], nums[j], toFind};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

// approach 3 - most optimised
vector<vector<int>> threeSum_o(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[k] + nums[j];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Approach:" << endl;
    vector<vector<int>> result_bf = threeSum_bf(nums);
    for (auto triplet : result_bf) {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }

    cout << "\nHashing Approach:" << endl;
    vector<vector<int>> result_hash = threeSum(nums);
    for (auto triplet : result_hash) {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }

    cout << "\nOptimized Two-Pointer Approach:" << endl;
    vector<vector<int>> result_opt = threeSum_o(nums);
    for (auto triplet : result_opt) {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
