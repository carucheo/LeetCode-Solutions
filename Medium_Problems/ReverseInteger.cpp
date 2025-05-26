/*
LeetCode Problem: Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the 32-bit signed integer range
[-2^31, 2^31 - 1], return 0.

Examples:
  Input: x = 123     → Output: 321
  Input: x = -123    → Output: -321
  Input: x = 120     → Output: 21

Approach:
  - Use modulo (%) to extract the last digit.
  - Use integer division (/) to remove the last digit from x.
  - Rebuild the reversed number by multiplying the current result by 10 and adding the digit.
  - Check for overflow before each multiplication/addition step.

Time Complexity: O(log₁₀(x)) — We process each digit once
Space Complexity: O(1) — Constant space used
Tags: Math, Integer Manipulation
*/

class Solution
{
public:
    int reverse(int x)
    {
        int reversed_num = 0;

        while (x != 0)
        {
            int digit = x % 10; // Extract the last digit
            x = x / 10;         // Remove the last digit from x

            // Check for overflow before multiplying
            if (reversed_num > INT_MAX / 10 || (reversed_num == INT_MAX / 10 && digit > 7))
                return 0;
            if (reversed_num < INT_MIN / 10 || (reversed_num == INT_MIN / 10 && digit < -8))
                return 0;

            reversed_num = reversed_num * 10 + digit; // Append the digit
        }

        return reversed_num;
    }
};
