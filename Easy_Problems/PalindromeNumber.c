/*
LeetCode Problem: Palindrome Number  
Link: https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is a palindrome, and false otherwise.

An integer is a palindrome when it reads the same backward as forward.
Negative numbers are not palindromes due to the minus sign.

Example:
  Input: x = 121
  Output: true

  Input: x = -121
  Output: false

  Input: x = 10
  Output: false

Approach:
  - Convert the integer to a string using sprintf.
  - Use two pointers (`left` and `right`) to compare characters from both ends of the string.
  - If any pair doesn't match, return false.
  - If the entire string is checked and all pairs match, return true.

Time Complexity: O(n) — where n is the number of digits in the number  
Space Complexity: O(1) — fixed-size buffer for string conversion  
Tags: Math, String, Two Pointers
*/

bool isPalindrome(int x) {
    char str[12];  // Enough to hold any 32-bit signed int (max 10 digits + sign + null)
    sprintf(str, "%d", x);  // Convert the integer to a string

    int left = 0;
    int right = strlen(str) - 1;  // In C, use 'strlen()' to get the size_t of the string/char array

    // Compare characters from both ends of the string
    while (left < right) {
        if (str[left] != str[right]) {
            return false;  // Mismatch found; not a palindrome
        }
        left++;
        right--;
    }

    return true;  // All characters matched; it's a palindrome
}