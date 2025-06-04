"""
LeetCode Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Roman numerals are represented by seven symbols: I, V, X, L, C, D, and M.
Each symbol has a corresponding integer value.

Sometimes, smaller values are placed before larger ones to indicate subtraction:
- I before V (5) or X (10) → 4, 9
- X before L (50) or C (100) → 40, 90
- C before D (500) or M (1000) → 400, 900

Given a string representing a valid Roman numeral, convert it to its integer value.

Example:
  Input: s = "MCMXCIV"
  Output: 1994
  Explanation: M=1000, CM=900, XC=90, IV=4

Approach:
  - Use a dictionary to map each Roman symbol to its value
  - Traverse the string left to right
  - If a smaller value precedes a larger one, subtract the smaller from the larger
  - Otherwise, just add the current value

Time Complexity: O(n) — where n is the length of the string
Space Complexity: O(1) — only a fixed-size dictionary is used
Tags: Hash Map, String, Greedy
"""

class Solution:
    def romanToInt(self, s: str) -> int:
        # Mapping of Roman numerals to their integer values
        roman = {"I": 1, "V": 5, "X": 10, "L": 50,
                 "C": 100, "D": 500, "M": 1000}

        result = 0  # Final integer value
        i = 0       # Index to traverse the input string

        while i < len(s):
            # Check if we're at a subtractive pair (e.g., IV, IX, etc.)
            if i + 1 < len(s) and roman[s[i]] < roman[s[i + 1]]:
                # Subtract current from next and add to result
                result += roman[s[i + 1]] - roman[s[i]]
                i += 2  # Move past the pair
            else:
                # Add value directly if no subtractive pattern
                result += roman[s[i]]
                i += 1  # Move to the next symbol

        return result