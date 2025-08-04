/**
 * Problem: Celebrity Problem
 * 
 * You are given a 2D matrix `arr` of size N x N where `arr[i][j] == 1` means person `i` knows person `j`,
 * and `arr[i][j] == 0` means person `i` does not know person `j`.
 * 
 * A celebrity is defined as someone who:
 * 1. Is known by everyone else (arr[i][celebrity] == 1 for all i != celebrity)
 * 2. Knows no one else (arr[celebrity][i] == 0 for all i)
 * 
 * Return the index of the celebrity if one exists, otherwise return -1.
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>> arr) {
    stack<int> s;
    int n = arr.size();

    // Step 1: Push everyone into the stack
    for(int i = 0; i < n; i++) s.push(i);

    // Step 2: Eliminate non-celebrities
    while(s.size() > 1){
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        // If a knows b, then a can't be celebrity
        if(arr[a][b] == 1) s.push(b);
        else s.push(a);
    }

    // Step 3: Verify the last person
    if(s.empty()) return -1;
    int celeb = s.top();

    for(int i = 0; i < n; i++) {
        if(i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
            return -1;
    }

    return celeb;
}

int main() {
    vector<vector<int>> test1 = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    cout << "Celebrity in Test Case 1: " << celebrity(test1) << endl; // Expected: 2

    vector<vector<int>> test2 = {
        {0, 1},
        {1, 0}
    };
    cout << "Celebrity in Test Case 2: " << celebrity(test2) << endl; // Expected: -1 (no celebrity)

    return 0;
}
