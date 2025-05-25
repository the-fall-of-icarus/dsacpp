#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <algorithm> // For max_element
using namespace std;

// Helper function to check if it is possible to paint with at most k painters
bool isPossible(const vector<int>& boards, int k, int maxTimeAllowed) {
    int painterCount = 1;
    int currentSum = 0;

    for (int length : boards) {
        if (length > maxTimeAllowed) return false; // Single board exceeds limit

        if (currentSum + length <= maxTimeAllowed) {
            currentSum += length;
        } else {
            painterCount++;
            currentSum = length;

            if (painterCount > k) return false;
        }
    }

    return true;
}

// Main function to find the minimum possible maximum time
int findMinTime(const vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end()); // At least the max board length
    int high = accumulate(boards.begin(), boards.end(), 0); // At most the sum of all
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, k, mid)) {
            result = mid;
            high = mid - 1; // Try for smaller maximum time
        } else {
            low = mid + 1; // Need more time
        }
    }

    return result;
}

int main() {
    vector<int> boards = {40, 30, 20, 10}; // Board lengths
    int k = 2; // Number of painters

    int minTime = findMinTime(boards, k);
    cout << "Minimum time to paint all boards with " << k << " painters: " << minTime << endl;

    return 0;
}
