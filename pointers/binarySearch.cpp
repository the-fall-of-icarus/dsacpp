#include<iostream>
#include<vector>
using namespace std;


//Iterative approach
int binarySearch_i(vector<int> arr, int target){
    int start=0;
    int end=arr.size()-1;
    int mid;

    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) start=mid+1;
        else if(target<arr[mid]) end=mid-1;
    }
    return -1;
}

//optimisation
//Calculate mid=start+((end-start)/2)

//recursive approach
int binarySearch_r(vector<int>arr, int target, int start, int end){
    int mid=start+(end-start)/2;

    if(start<=end){
        if(target==arr[mid]) return mid;
        else if(target>arr[mid]) return binarySearch_r(arr,target,mid+1,target);
        else if(target<arr[mid]) return binarySearch_r(arr,target,start,mid-1);
    }
    return -1;
}

int main(){
    vector<int> a1={1,2,3,4,5,6,7,8};
    vector<int> a2={2,6,9,14,23,34,47,67,89,90};

    int a = binarySearch_i(a1, 2);
    int b = binarySearch_i(a2, 90);
    int c = binarySearch_i(a2, 91);

    cout<< "For 2 in array 1: " << a << endl;
    cout << "For 90 in array 2: " << b<< endl;
    cout << "For 91 in array 2: " << c << endl;

    //results from recursive approach
    int aa = binarySearch_r(a1, 2,0,7);
    int b1 = binarySearch_r(a2, 90,0,9);
    int c1 = binarySearch_r(a2, 91,0,9);

    cout << "For 2 in array 1: " << aa << endl;
    cout << "For 90 in array 2: " << b1 << endl;
    cout << "For 91 in array 2: " << c1 << endl;

    return 0;
}