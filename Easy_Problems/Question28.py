"""
LeetCode Problem: 28. Find the Index of the First Occurrence in a String
Difficulty: Easy

Description:
Given two strings `needle` and `haystack`, return the index of the first 
occurrence of `needle` in `haystack`, or -1 if `needle` is not part of `haystack`.

Examples:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Input: haystack = "leetcode", needle = "leeto"
Output: -1

Approach:
- Check every possible starting position in `haystack` where `needle` could match
- For each position, compare characters in `needle` with the corresponding characters in `haystack`
- If all characters match for a given position, return that index
- If no match is found after scanning all positions, return -1

Time Complexity: O(n * m), where n is the length of `haystack` and m is the length of `needle`
Space Complexity: O(1)
"""

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # Early exit if needle is longer than haystack
        if len(needle) > len(haystack):
            return -1

        # Loop through each possible starting index in haystack
        for i in range(len(haystack) - len(needle) + 1):
            match = True  # Assume it's a match until proven otherwise

            # Check each character in needle
            for j in range(len(needle)):
                if haystack[i + j] != needle[j]:
                    match = False
                    break  # Exit inner loop early on mismatch

            # If full needle matched, return the start index
            if match:
                return i

        # No match found
        return -1
