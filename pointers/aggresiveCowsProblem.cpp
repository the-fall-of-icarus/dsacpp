#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it's possible to place cows with at least 'minDist' distance
bool canPlaceCows(const vector<int>& stalls, int cows, int minDist) { //O(N) where N is the total number of stalls we have
    int count = 1; // First cow is placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= cows) return true;
    }

    return false;
}

// Function to find the largest minimum distance between cows
int aggressiveCows(vector<int>& stalls, int cows) { //O(log(range)*N)
    sort(stalls.begin(), stalls.end()); // Sort stall positions

    int low = 1;
    int high = stalls.back() - stalls.front();
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid)) {
            result = mid;       // Mid is a valid answer, try for larger
            low = mid + 1;
        } else {
            high = mid - 1;     // Mid is too large, reduce
        }
    }

    return result;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9}; // Stall positions
    int cows = 3;

    int maxMinDistance = aggressiveCows(stalls, cows);
    cout << "The largest minimum distance is: " << maxMinDistance << endl;

    return 0;
}
