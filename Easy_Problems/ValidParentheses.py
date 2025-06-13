"""
LeetCode Problem: 20. Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/

Problem:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Every closing bracket has a corresponding open bracket of the same type.

Examples:
  Input: s = "()"
  Output: True

  Input: s = "()[]{}"
  Output: True

  Input: s = "(]"
  Output: False

Approach:
- Use a stack to track opening brackets.
- Iterate through each character in the string:
  - If it's an opening bracket, push it onto the stack.
  - If it's a closing bracket:
    - If the stack is empty, return False (no matching opening bracket).
    - Check if the top of the stack matches the corresponding opening bracket.
    - If it doesn't match, return False.
    - If it matches, pop the top bracket from the stack.
- After processing all characters, if the stack is empty, return True (all brackets matched).
- Otherwise, return False.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(n), worst case when all characters are opening brackets.
Tags: Stack, String, Brackets, Validation
"""

class Solution:
    def isValid(self, s: str) -> bool:
        # If the input string is empty, it's considered valid
        if len(s) == 0:
            return True

        stack = []  # Initialize an empty stack to keep track of opening brackets

        for c in s:
            # If current char is an opening bracket, push it onto the stack
            if c == "(" or c == "{" or c == "[":
                stack.append(c)
            else:
                # If closing bracket found but stack is empty, no match -> invalid
                if len(stack) == 0:
                    return False

                top = stack[-1]  # Peek the top element of the stack without popping

                # Check if current closing bracket matches the last opening bracket
                if (
                    (c == ")" and top != "(")
                    or (c == "}" and top != "{")
                    or (c == "]" and top != "[")
                ):
                    return False  # Mismatched bracket found

                stack.pop()  # Pop the matched opening bracket from the stack

        # If stack is empty, all brackets matched; otherwise, invalid
        return len(stack) == 0
