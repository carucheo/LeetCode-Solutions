"""
LeetCode Problem: 58. Length of Last Word
Link: https://leetcode.com/problems/length-of-last-word/

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is defined as a maximal substring consisting of non-space characters only.

Approach:
- Loop through the string in reverse using a for loop
- Skip trailing spaces
- Start counting when a non-space character is found
- Stop counting when a space is encountered after counting has started

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0

        # Iterate from end to start of the string
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                # Break if a space is found after counting has started
                if count > 0:
                    break
                continue
            else:
                count += 1  # Count the characters of the last word

        return count

"""
LeetCode Problem: 58. Length of Last Word
Difficulty: Easy

Approach:
- Use two while loops:
    1. Skip trailing spaces from the end of the string
    2. Count the length of the last word by checking non-space characters
- Return the final count

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        i = len(s) - 1  # Start from the last index

        # Skip trailing spaces
        while i >= 0 and s[i] == ' ':
            i -= 1

        # Count characters of the last word
        while i >= 0 and s[i] != ' ':
            count += 1
            i -= 1

        return count
