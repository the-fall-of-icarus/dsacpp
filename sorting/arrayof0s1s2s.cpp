#include <iostream>
#include <vector>
using namespace std;

//approach1
void sortColors(vector<int>& a) {
      int n = a.size();
        int count0 = 0, count1 = 0, count2 = 0;

        // Count the number of 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) count0++;
            else if (a[i] == 1) count1++;
            else if (a[i] == 2) count2++;
        }

        // Fill the array with 0s, then 1s, then 2s
        int i = 0;
        while (count0--) a[i++] = 0;
        while (count1--) a[i++] = 1;
        while (count2--) a[i++] = 2;
}

//one pass approach - Dutch national flag algorithm
//o(n) time complexity and O(1) space complexity
void sortColors_dnf(vector<int>& a) {
      int n = a.size();
        int mid=0, low=0, high=n-1;

        while(mid<=high){
            if(a[mid]==0){
                swap(a[mid],a[low]);
                low++;
                mid++;
            }
            else if(a[mid]==1) mid++;

            else{
                swap(a[mid], a[high]);
                high--;
            }
        }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int>a={2,0,2,2,2,0,1,2,0,0};
    cout << "the array: ";
    printArray(a);
    sortColors_dnf(a);
    cout<< "the array after sorting using DNF algorithm: ";
    printArray(a);

    return 0;
}
