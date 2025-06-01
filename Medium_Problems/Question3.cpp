/*
LeetCode Problem: Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, return the length of the longest substring without repeating characters.

Examples:
  Input:  s = "abcabcbb"
  Output: 3 → "abc"

  Input:  s = "bbbbb"
  Output: 1 → "b"

  Input:  s = "pwwkew"
  Output: 3 → "wke"

Approach:
  - Use a sliding window with two pointers (`left` and `right`) to track the current substring
  - Use a set to keep track of characters seen so far
  - If a character is not in the set, add it and update the max length
  - If a character is repeated, remove the leftmost character and move `left` forward
  - Continue until `right` reaches the end of the string

Time Complexity: O(n) — each character is added and removed from the set at most once
Space Complexity: O(k) — where k is the size of the character set (at most 128 for ASCII)
Tags: String, Sliding Window, Hash Set, Two Pointers
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> seen;  // Stores characters in the current window
        int left = 0;    // Start of the current window
        int right = 0;   // End of the current window
        int max_len = 0; // Stores the maximum length found

        while (right < s.length())
        {
            if (seen.count(s[right]) == 0)
            {
                // Character not seen — extend the window
                seen.insert(s[right]);
                max_len = max(max_len, right - left + 1); // Update max length
                right++;                                  // Move right pointer forward
            }
            else
            {
                // Duplicate found — shrink the window from the left
                seen.erase(s[left]);
                left++; // Move left pointer forward
            }
        }

        return max_len; // Return the maximum length found
    }
};