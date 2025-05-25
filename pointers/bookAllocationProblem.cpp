#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxallowedPages){
    int student=1, pages=0;
    
    for(int i=0; i<n; i++){

        if(arr[i]>maxallowedPages) return false;

        if(pages + arr[i]<=maxallowedPages){
            pages+=arr[i];
        }
        else{
            student++;
            pages=arr[i];
        }
    }
    return student>m?false:true;
}

int allocatebook(vector<int> &arr, int n, int m){
    if(m>n) return -1;

    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    int start=0, end=sum;
    int ans;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
}

//overall timecomplexity: O(logn * N) where n is the total number of books we have and N is the range on which we we are applying our binary search that is o to sum(array)

int main(){
    vector<int> arr={2,1,3,4};
    int n1=4, m1=2;

    cout << allocatebook(arr, n1, m1) << endl;
    cout << allocatebook(arr, 4, 5) << endl;

    return 0;
}