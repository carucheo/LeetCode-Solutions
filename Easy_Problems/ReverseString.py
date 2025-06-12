"""
LeetCode Problem: 344. Reverse String
Link: https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters `s`.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
  Input:  s = ["h", "e", "l", "l", "o"]
  Output: ["o", "l", "l", "e", "h"]

Example 2:
  Input:  s = ["H", "a", "n", "n", "a", "h"]
  Output: ["h", "a", "n", "n", "a", "H"]

Approach:
  - Use the two-pointer technique:
    - One pointer starts from the beginning (`left`)
    - One pointer starts from the end (`right`)
  - Swap the characters at `left` and `right`, then move both inward
  - Repeat until the pointers meet or cross
  - This performs the reversal in-place with constant extra memory

Time Complexity: O(n) — each element is visited once  
Space Complexity: O(1) — no additional memory used  
Tags: Two Pointers, String, In-Place Modification
"""

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # Initialize two pointers: one at the beginning and one at the end
        left = 0
        right = len(s) - 1

        # Continue swapping until the two pointers meet or cross
        while left < right:
            # Swap the elements at the left and right positions
            s[left], s[right] = s[right], s[left]

            # Move the left pointer one step to the right
            left += 1

            # Move the right pointer one step to the left
            right -= 1