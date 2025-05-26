"""
LeetCode Problem: Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the 32-bit signed integer range
[-2^31, 2^31 - 1], return 0.

Examples:
  Input: x = 123      → Output: 321
  Input: x = -123     → Output: -321
  Input: x = 120      → Output: 21

Approach:
  - Extract the sign of x and work with its absolute value
  - Use modulo and integer division to peel off digits from the right
  - Rebuild the reversed number digit by digit
  - Before each step, check for 32-bit overflow risk
  - Return 0 if the result would exceed the signed 32-bit range

Time Complexity: O(log₁₀(x)) — processes each digit once
Space Complexity: O(1) — constant space used
Tags: Math, Integer Manipulation
"""

class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -2**31        # -2147483648
        INT_MAX = 2**31 - 1     # 2147483647

        # Track the sign and work with the absolute value
        sign = -1 if x < 0 else 1
        x = abs(x)

        reversed_num = 0

        while x != 0:
            digit = x % 10
            x //= 10

            # Check for overflow BEFORE it happens
            if reversed_num > INT_MAX // 10 or (reversed_num == INT_MAX // 10 and digit > 7):
                return 0

            # Build the reversed number
            reversed_num = reversed_num * 10 + digit

        # Restore the sign at the end
        return sign * reversed_num
