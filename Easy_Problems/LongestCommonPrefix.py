"""
LeetCode Problem: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/

Problem:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example:
  Input:  strs = ["flower", "flow", "flight"]
  Output: "fl"

Approach:
  - Use the first string as an initial candidate for the prefix.
  - Compare this prefix with each string in the list.
  - If the current string does not start with the prefix, trim the last character from the prefix.
  - Repeat trimming until the prefix matches the beginning of the current string.
  - Stop early and return "" if the prefix becomes empty.

Time Complexity: O(S), where S is the sum of all characters in all strings
Space Complexity: O(1) — we reuse the input and only keep a small prefix string
Tags: String, Prefix, Iterative
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Edge case: if the input list is empty, return an empty string
        if len(strs) == 0:
            return ""

        # Initialize prefix to the first string in the list
        prefix = strs[0]

        # Loop through each string starting from the second one
        for i in range(1, len(strs)):
            # While the current string does not start with the prefix
            while strs[i][:len(prefix)] != prefix:
                # Remove the last character from prefix to try a shorter prefix
                prefix = prefix[:-1]

                # If prefix is empty, it means no common prefix exists
                if len(prefix) == 0:
                    return ""

        # Return the longest common prefix after checking all strings
        return prefix
