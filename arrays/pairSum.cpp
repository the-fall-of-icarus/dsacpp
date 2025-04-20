#include<iostream>
#include<vector>
using namespace std;

//brute force approach
vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    int n=nums.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
}

vector<int> pairSum2(vector <int> nums, int target){
    vector<int> ans;
    int n=nums.size();
    int ps;
    int i=0, j=n-1;
    while(i<j){
       ps=nums[i]+nums[j];
       if(ps<target) i++;
       else if(ps>target) j--;
       else{
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        return ans;
       }
    }
}
 
int main(){

    cout<< "Brute Force: " << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = pairSum(nums, 5);
    cout<< ans[0] << " " << ans[1] << endl;

    cout << "Optimization in Brute Force: " << endl;
    vector<int> ans2 = pairSum2(nums, 9);
    cout<< ans2[0] << " " << ans2[1] << endl;
    return 0;
}