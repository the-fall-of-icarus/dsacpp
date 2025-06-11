#include<iostream>
#include<vector>
using namespace std;

int countInversions_bf(vector<int> &arr){
    int n=arr.size();
    int count=0;
    for(int i=0; i<(n-1);i++){
        for(int j=i; j<n; j++){
            if(arr[i]>arr[j]) count++;
        }
    }
    return count;
}

int merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i=st, j=mid+1;
    int invCount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invCount+=(mid-i+1);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int index=0; index<temp.size(); index++){
        arr[index+st]=temp[index];
    }

    return invCount;
}

int mergesort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;
        int leftcount = mergesort(arr, st, mid);
        int rightcount = mergesort(arr, mid+1, end);
        int invCount = merge(arr, st, mid, end);
        return leftcount+rightcount+invCount;
    }
    return 0;
}

int main(){
    vector<int> arr ={6,3,5,2,7};
    vector<int> arr2 = {1,3,5,10,2,6,8,9};
    cout << "Inversions (brute force approach):" << countInversions_bf(arr) << endl;
    cout << "Inversions (using merge sort logic): " << mergesort(arr2,0,arr2.size()-1) << endl;
    return 0;
}