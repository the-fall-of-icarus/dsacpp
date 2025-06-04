/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 
*/

#include<iostream>
#include<vector>
using namespace std;
/*
    void setZeroes(vector<vector<int>>& matrix) {
       int rows = matrix.size(), cols = matrix[0].size();
        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        // Mark zeros
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        // Set zero rows
        for (int i = 0; i < rows; i++){
            if (zeroRows[i]) {
                for (int j = 0; j < cols; j++) matrix[i][j] = 0;
            }
        }

        // Set zero cols
        for (int j = 0; j < cols; j++){
            if (zeroCols[j]) {
                for (int i = 0; i < rows; i++) matrix[i][j] = 0;
            }
        }
    }
*/
//optimal approach
void zeroMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j != 0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < cols; j++) matrix[0][j] = 0;
    }

    if (col0 == 0) {
        for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    
    cout << "Before applying the function:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    zeroMatrix(matrix);

    cout << "After applying the function:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}