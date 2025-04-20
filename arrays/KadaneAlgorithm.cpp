#include<iostream>
#include<vector>
using namespace std;

int kadane(vector<int> &nums){
    int cs=0;
        int maxSum=INT16_MIN;

        for(int val: nums){
            cs+=val;
            maxSum=max(maxSum,cs);
            if(cs<0) cs=0;
        }
        return maxSum;
}

int main(){
    int n=5;
    int arr[5] = {1,2,3,4,5};

    vector<int>a={3,-4,5,4,-1,7,-8};


    //brute force approach
    int maxSum = INT16_MIN;
    for(int st=0; st<n; st++){
        int currSum=0;
        for(int end=st; end<n; end++){
            currSum+=arr[end];
            maxSum=max(currSum, maxSum);
        }
    }
    cout<<maxSum<<endl;

    cout<< "Using Kadane's Algortihm: ";
    cout<< kadane(a)<<endl;

    return 0;
}