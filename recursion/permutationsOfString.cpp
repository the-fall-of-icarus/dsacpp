/*
    Problem: Generate All Permutations of a String

    Given a string `s`, generate all possible permutations of the characters in the string.

    Example:
    Input: "abc"
    Output: 
        abc
        acb
        bac
        bca
        cab
        cba

    Approach:
    - Use backtracking with swapping to generate permutations.
    - At each step, fix one character and recursively permute the rest.
    - Swap back to restore original state for other branches (backtracking).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void getPermutations(string &s, vector<string> &ans, int i) {
    if (i == s.size()) {
        ans.push_back(s);
        return;
    }

    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);                      // fix the i-th character
        getPermutations(s, ans, i + 1);        // permute the rest
        swap(s[i], s[j]);                      // backtrack
    }
}

int main() {
    string s = "abcd";  // You can change this input
    vector<string> permutations;

    getPermutations(s, permutations, 0);

    cout << "All permutations of \"" << s << "\":" << endl;
    for (const string &perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
