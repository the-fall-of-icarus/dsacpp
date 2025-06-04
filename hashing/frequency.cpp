#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void countFrequency(const vector<int> &arr){
    unordered_map<int, int> freq;
    for(int i: arr){
        freq[i]++;
    }

    for(auto it: freq){
        cout << it.first << " : " << it.second << endl;
    }
}

int main(){
    vector<int> arr1 = {10,5,10,15,10,5};
    countFrequency(arr1);
    return 0;
}