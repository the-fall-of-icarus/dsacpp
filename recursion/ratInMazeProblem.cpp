#include<iostream>
#include<vector>
#include<string>
using namespace std;

void findPath(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans){
    int n = mat.size();
    
    // Boundary and validity check
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) 
        return;

    // Destination reached
    if(r == n - 1 && c == n - 1){
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited
    mat[r][c] = -1;

    // Explore all 4 directions: Down, Left, Right, Up
    findPath(mat, r + 1, c, path + "D", ans);
    findPath(mat, r, c - 1, path + "L", ans);
    findPath(mat, r, c + 1, path + "R", ans);
    findPath(mat, r - 1, c, path + "U", ans);

    // Backtrack
    mat[r][c] = 1;
}

int main(){
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = mat.size();
    vector<string> ans;
    string path = "";

    findPath(mat, 0, 0, path, ans);

    for(string p : ans){
        cout << p << endl;
    }

    return 0;
}
