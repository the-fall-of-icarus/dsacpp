#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//Problem: Product of Array except self

//Approach 1: Brute Force Approach
vector<int> productExceptSelf_bf(vector<int>& nums) {
    int s = nums.size();
    vector<int>ans(s, 1);
    for(int i=0; i<s; i++){
        int product=1;
        for(int j=0; j<s; j++){
            if(i!=j){
                product=product*nums[j];
            }
        }
        ans[i] = product;
    }  
    return ans; 
}

//Optimised Approach 
vector<int> productExceptSelf_o(vector<int>& nums) {
    int s = nums.size();
    vector<int>ans(s, 1);
    vector<int>prefix(s, 1);
    vector<int>suffix(s, 1);
    for(int i=1;i<s; i++){
        prefix[i]=prefix[i-1]*nums[i-1];
    }
    for(int j=s-2; j>=0; j--){
        suffix[j]=suffix[j+1]*nums[j+1];
    }
    for(int i=0;i<s; i++){
        ans[i] = prefix[i]*suffix[i];
    }

    return ans;
}

//space complexity optimization
vector<int> productExceptSelf_os(vector<int>& nums) {
   int s = nums.size();
    vector<int>ans(s, 1); 
    int suffix=1;

    for(int i=1; i<s; i++){
        ans[i]=ans[i-1]*nums[i-1];
    }
    for(int j=s-2; j>=0; j--){
        suffix*=nums[j+1];
        ans[j]*=suffix;
    }

    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    
    vector<int> result1 = productExceptSelf_bf(nums);
    vector<int> result2 = productExceptSelf_o(nums);
    vector<int> result3 = productExceptSelf_os(nums);
    
    cout << "The answer from brute force approach:" << endl;
    for(int val : result1){
        cout << val << " ";
    }
    cout << endl;

    cout << "The answer from time complexity optimised approach:" << endl;
    for(int val : result2){
        cout << val << " ";
    }
    cout << endl;

    cout << "The answer from time and space complexity optimised approach:" << endl;
    for(int val : result3){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}