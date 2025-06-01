"""
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
  - Use a set to store characters currently in the window
  - If the character at `right` is not in the set:
      - Add it to the set and update the max length
  - If it is already in the set:
      - Remove the leftmost character and move `left` forward to shrink the window
  - Repeat until the entire string has been scanned

Time Complexity: O(n) — each character is visited at most twice  
Space Complexity: O(k) — where k is the size of the character set (at most 128 for ASCII)  
Tags: String, Sliding Window, Hash Set, Two Pointers
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()          # Set to store characters in the current window
        left = 0              # Left pointer of the window
        right = 0             # Right pointer of the window
        max_len = 0           # Track the maximum length found

        while right < len(s):
            if s[right] not in seen:
                seen.add(s[right])                          # Add character to the set
                max_len = max(max_len, right - left + 1)    # Update max length
                right += 1                                  # Expand the window
            else:
                seen.remove(s[left])                        # Shrink the window from the left
                left += 1

        return max_len
