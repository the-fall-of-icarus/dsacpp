#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Convert to lowercase for comparison
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha; // to print true/false instead of 1/0
    cout << "s1: " << sol.isPalindrome(s1) << endl; // true
    cout << "s2: " << sol.isPalindrome(s2) << endl; // false
    cout << "s3: " << sol.isPalindrome(s3) << endl; // true

    return 0;
}
