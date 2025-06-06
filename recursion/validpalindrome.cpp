/*
    Problem: Check if a String is a Palindrome using Recursion

    A palindrome is a string that reads the same forward and backward.

    Examples:
    Input: "madam"    → Output: Palindrome
    Input: "racecar"  → Output: Palindrome
    Input: "hello"    → Output: Not a Palindrome

    Approach:
    - Use two pointers: one starting from the beginning and one from the end.
    - If the characters at both positions match, recursively check the remaining substring.
    - Base case: If left >= right, it means we have checked the entire string.
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int left, int right) {
    if (left >= right) return true; // base case: all characters matched
    if (s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1); // recursive call
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (isPalindrome(s, 0, s.length() - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}
