#include<vector>
#include <iostream>
using namespace std;

int linearSearch(vector<int>& vec, int target){
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == target){
            return i;
        }
    }
}

void reverse(vector<int> &vec){
    int start=0, end=vec.size() - 1;
    while(start<end){
        swap(vec[start], vec[end]);
        start++;
        end--;
    }  
    return;     
}

int main(){
    /*vector<int>vec1;
    vector<int>vec2 = {1,2,4};
    vector<int>vec3(3,0); //size of vector is 3 and at each index, 0 is stored.
    cout << vec2[2] << endl;
    
    vec1.push_back(30);
    vec1.push_back(33);
    vec1.push_back(36);
    vec1.push_back(39);
    cout << vec1.size();
    vec1.pop_back();
    cout << vec1.size();
    cout << vec1.front();
    cout<< vec1.back();
    cout<< vec1.at(2);
    for(int val: vec3){
        cout << val << endl;
    }
*/
    vector<int> vec={4,8,7,3,9,0};
    int ans = linearSearch(vec, 9);
    cout << "The target is available at index: " << ans << endl;

    cout << "Before reversing: ";
    for(int val: vec){
        cout << val << " ";
    }
    cout<< endl;
    reverse(vec);
    cout << "After reversing: ";
    for(int val: vec){
        cout << val << " ";
    }
    return 0;
} 