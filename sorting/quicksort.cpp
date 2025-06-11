#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int index=st-1, pivot=arr[end];
    for(int j=st; j<end; j++){
        if(arr[j]>=pivot){ //sorting in descending manner
            index++;
            swap(arr[index], arr[j]);
        }
    }
    index++;
    swap(arr[end], arr[index]);
    return index;
}

void quicksort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivIdx=partition(arr, st, end);
        quicksort(arr, st, pivIdx-1);
        quicksort(arr, pivIdx+1, end);
    }
}

int main(){
    vector<int> arr = {5, 3, 8, 4, 2, 9, 1, 11};

    cout << "Original array:\n";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}