#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int mj1(vector<int> &nums){
    int n=nums.size();
    for(int val : nums){
        int freq=0;
        for(int el : nums){
            if(val==el) freq++;
        }
        if(freq > (n/2)) return val;
    }
}

int mj2(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(), nums.end());

    int freq=1;
    int ans=nums[0];
    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]){
            freq++;
        } 
        else{
            freq=1;
            ans=nums[i];
        }
        if(freq>(n/2)) {
            return ans;
    }
    }
}

int moooreVotingAlgo(vector<int> &nums){
    int freq=1, ans=0;
    for(int i=1; i<nums.size(); i++){
        if(freq==0) ans = nums[i];
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,2,2,2,2,3};
    cout << mj1(nums) << endl;
    cout << mj2(nums) << endl;
    cout << moooreVotingAlgo(nums) << endl;

    return 0;
}