"""
LeetCode Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/

Given an integer x, return True if x is a palindrome, and False otherwise.

A palindrome is a number that reads the same forward and backward.

Examples:
  Input: x = 121
  Output: True

  Input: x = -121
  Output: False
  Explanation: From left to right, it reads -121. From right to left, it becomes 121-.

  Input: x = 10
  Output: False
  Explanation: Reads 01 from right to left.

Approach:
  - Convert the integer to a string using str(x)
  - Use two pointers: one at the start, one at the end of the string
  - Compare characters while moving inward
  - If all pairs match, the number is a palindrome

Time Complexity: O(n) — where n is the number of digits
Space Complexity: O(n) — for the string conversion
Tags: Math, String, Two Pointers
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = str(x)
        left = 0
        right = len(num) - 1

        while left < right:
            if num[left] != num[right]:
                return False
            left += 1
            right -= 1

        return True
