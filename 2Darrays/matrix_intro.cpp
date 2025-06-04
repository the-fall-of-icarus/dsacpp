#include <iostream>
#include<climits>
using namespace std;

bool linearSearch(int m[][3], int rows, int cols, int key){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(m[i][j]==key) return true;
        }
    }
    return false;
}

pair<int, int> linearSearch2D(int matrix[][3], int rows, int cols, int target){
    if(rows == 0) return {-1,-1};

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j]==target){
                return {i,j};
            
            }
        }
    }
    return {-1,-1};
}

int maxColSum(int matrix[][3], int rows, int cols){
    int maxColsSum=INT_MIN;
    for(int i=0; i<cols; i++){
        int colSumI=0;
        for(int j=0; j<rows; j++){
            colSumI += matrix[j][i];
        }
        maxColsSum=max(maxColsSum,colSumI);
    }
    return maxColsSum;
}

int main(){
    int matrix[4][3];
    int rows=4;
    int cols=3;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> matrix[i][j];
        }
    }

    cout << linearSearch(matrix,rows, cols, 2) << endl;

    pair<int, int> result = linearSearch2D(matrix,rows,cols,6);

    if (result.first != -1) {
        cout << "Element found at: (" << result.first << ", " << result.second << ")\n";
    } else {
        cout << "Element not found.\n";
    }

    cout << "Maximum column sum: " << maxColSum(matrix,rows,cols) << endl;


    return 0;

}