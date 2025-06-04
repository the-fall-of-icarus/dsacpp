#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

pair<int, int> findDuplicateAndMissing(vector<vector<int>>& matrix) {
    int n = matrix.size();
    unordered_set<int> seen;
    int duplicate = -1;
    int missing = -1;

    // Mark seen numbers and find duplicate
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = matrix[i][j];
            if (seen.find(val) != seen.end()) {
                duplicate = val;
            } else {
                seen.insert(val);
            }
        }
    }

    // Find missing
    for (int i = 1; i <= n * n; ++i) {
        if (seen.find(i) == seen.end()) {
            missing = i;
            break;
        }
    }

    return {duplicate, missing};
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2},
        {2, 4}
    };

    pair<int, int> result = findDuplicateAndMissing(matrix);
    cout << "Duplicate = " << result.first << ", Missing = " << result.second << endl;

    return 0;
}
