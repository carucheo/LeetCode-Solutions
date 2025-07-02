"""
LeetCode Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/

Problem:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.

Return True if the given string is a palindrome; otherwise, return False.

Example 1:
  Input:  s = "A man, a plan, a canal: Panama"
  Output: True

Example 2:
  Input:  s = "race a car"
  Output: False

Example 3:
  Input:  s = " "
  Output: True

Approach:
  - Iterate through the original string and build a new string with only alphanumeric characters.
  - Convert all kept characters to lowercase during construction.
  - Use two-pointer technique to compare characters from both ends of the cleaned string.
  - If all characters match, it's a palindrome.

Time Complexity: O(n) — One pass to clean, one pass to check
Space Complexity: O(n) — Extra string used to store cleaned version
Tags: String, Two Pointers
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = ""  # Declare variable for a cleaned, lowercase version of the input string
        
        # Step 1: Build a cleaned lowercase alphanumeric string
        for char in s:
            if char.isalnum():
                cleaned += char.lower()

        left = 0
        right = len(cleaned) - 1

        # Step 2: Compare characters from both ends using two-pointer technique
        while left < right:
            if cleaned[left] != cleaned[right]:
                return False  # Mismatch found — not a palindrome
            
            left += 1
            right -= 1  # Move both pointers inward

        return True  # All matched — valid palindrome