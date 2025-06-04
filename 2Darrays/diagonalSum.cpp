#include <iostream>
using namespace std;

int diagonalSum(int matrix[][4], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j || j == n - i - 1)
                sum += matrix[i][j];
        }
    }

    return sum;
}

int main() {
    const int n = 4; // rows and cols
    int matrix[n][4] = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 9, 21, 23},
        {25, 27, 29, 31}
    };

    cout << "Diagonal Sum: " << diagonalSum(matrix, n) << endl;
    return 0;
}
