#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int size){
    int i=0, j=size-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int sum(int arr[], int size){
    int s=0;
    for(int i=0; i<size; i++){
        s+=arr[i];
    }
    return s;
}

int product(int arr[], int size){
    int p=1;
    for(int i=0; i<size; i++){
        p*=arr[i];
    }
    return p;
}

void swapMinMax(int arr[], int size){
    if(size==0) return;

    int minIndex=0; int maxIndex=0;
    for(int i=0; i<size; i++){
        if(arr[i]<arr[minIndex]) minIndex=i;
        if(arr[i]>arr[maxIndex]) maxIndex=i;
    }

    swap(arr[minIndex], arr[maxIndex]);
}

void intersection(int arr1[], int size1, int arr2[], int size2){
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(arr1[i]==arr2[j]){
                cout << arr1[i] << " ";
         
            }   
        }
    }
    cout<< endl;
}

void printUnique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int isUnique = 1;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}


int main(){
    /*
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr [3] >> arr[4];

    arr[3] += 10;
    cout << arr[3];

    arr[2] = 14;
    cout <<"\n" << arr[2];

    cout << "\n**2D-ARRAY**\n";
    int arr2[3][3];
    cout << arr2[2][2];
    */

    int a[] = {4,7,2,8,1,2,5};
    int sz1 = sizeof(a)/sizeof(a[0]);
    reverse(a, sz1);

    cout<< "Reversed array: ";
    for(int i=0; i<sz1; i++){
        cout<<a[i] << " ";
    }
    cout << endl;

    cout << "The sum of all elements of the array is: " << sum(a,sz1) << endl;
    cout << "The Product of all elements of the array is: " << product(a,sz1) << endl;

    cout<< "Array after swapping minimum and maximum elements: ";
    swapMinMax(a,sz1);
    for(int i=0; i<sz1; i++){
        cout<<a[i] << " ";
    }
    cout << endl;

    int b[]={1,3,5,7,9,1,3,3,5,9,7,7,5,9};
    int sz2=sizeof(b)/sizeof(b[0]);
    cout<<"The intersection of two arrays is: ";
    intersection(a,sz1,b,sz2);

    cout<< "Unique elements of Array b: ";
    printUnique(b, sz2);

    return 0;
}