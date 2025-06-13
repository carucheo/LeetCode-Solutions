/*
LeetCode Problem: 20. Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/

Problem:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
  - Open brackets must be closed by the same type of brackets.
  - Open brackets must be closed in the correct order.
  - Every close bracket must have a corresponding open bracket.

Examples:
  Input: s = "()"
  Output: true

  Input: s = "()[]{}"
  Output: true

  Input: s = "(]"
  Output: false

Approach:
  - Use a stack to keep track of opening brackets.
  - Iterate through the string character by character.
  - If the character is an opening bracket, push it onto the stack.
  - If it's a closing bracket, check the top of the stack:
      - If it matches the corresponding opening bracket, pop the stack.
      - If not, or if the stack is empty, return false.
  - After the loop, if the stack is empty, return true (all brackets matched).
    Otherwise, return false.

Time Complexity: O(n), where n is the length of the string
Space Complexity: O(n), for the stack in the worst case
Tags: Stack, String, Validation
*/

class Solution
{
public:
    bool isValid(string s)
    {
        // Edge case: an empty string is considered valid
        if (s == "")
            return true;

        stack<char> brackets; // Stack to track opening brackets

        // Traverse each character in the input string
        for (int i = 0; i < s.length(); i++)
        {
            // If current character is an opening bracket, push it to stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                brackets.push(s[i]);
            }
            else
            {
                // If stack is empty and we see a closing bracket, it's invalid
                if (brackets.empty())
                    return false;

                // Check if the top of the stack matches the closing bracket
                char top = brackets.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == ']' && top != '[') ||
                    (s[i] == '}' && top != '{'))
                {
                    return false; // Mismatched bracket
                }

                // Pop the matched opening bracket
                brackets.pop();
            }
        }

        // If the stack is empty, all brackets were matched correctly
        return brackets.empty();
    }
};
