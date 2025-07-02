/*
LeetCode Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/

Problem:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.
Return true if the given string is a palindrome, false otherwise.

Example 1:
  Input:  s = "A man, a plan, a canal: Panama"
  Output: true

Example 2:
  Input:  s = "race a car"
  Output: false

Example 3:
  Input:  s = " "
  Output: true

Approach:
  - Iterate through the input string and build a new string with only lowercase alphanumeric characters.
  - Use two pointers (left and right) to compare characters from both ends of the cleaned string.
  - If all matching characters are equal, return true. If any mismatch is found, return false.

Time Complexity: O(n) — Single pass to clean and single pass to check palindrome
Space Complexity: O(n) — Extra space used to store the cleaned string
Tags: String, Two Pointers
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string cleaned = "";

        // Step 1: Build a cleaned lowercase alphanumeric string
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {                                                // Keep only letters and digits
                cleaned += static_cast<char>(tolower(s[i])); // Normalize to lowercase
            }
        }

        int left = 0;
        int right = cleaned.length() - 1;

        // Step 2: Use two pointers to check for palindrome
        while (left < right)
        {
            if (cleaned[left] != cleaned[right])
            {
                return false; // Mismatch found — not a palindrome
            }
            left++;  // Move from start forward
            right--; // Move from end backward
        }

        return true; // All characters matched — it's a palindrome
    }
};