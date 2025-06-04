#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &matrix){
    int rows=matrix.size();
    int cols=matrix[0].size();

    for(int i=0; i<rows; i++){
        for(int j=i+1; j<cols; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<rows; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "The matrix: " << endl;
    printMatrix(matrix);
    rotateMatrix(matrix);
    cout << "Rotated matrix: " << endl;
    printMatrix(matrix);
    return 0;
}