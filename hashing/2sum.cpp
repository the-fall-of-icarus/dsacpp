#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

pair<int, int> twoSum(vector<int> &a, int target){
    unordered_map<int,int> map;
    for(int i=0; i<a.size(); i++){
        int first=a[i];
        int sec=target-first;
        if(map.find(sec)!=map.end()){
            return {i,map[sec]};
        }
        else{
            map[first]=i;
        }
    }
    return {-1,-1};
}

int main(){
    vector<int> arr ={5,2,1,11,7,6};
    pair<int,int> ans = twoSum(arr,9);
    cout<< " The pair that sums up the target is at indices: " << ans.first << "," << ans.second << endl;

    return 0;
}