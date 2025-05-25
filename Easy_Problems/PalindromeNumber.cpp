/*
LeetCode Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is a palindrome, and false otherwise.

A palindrome is a number that reads the same forward and backward.

Examples:
  Input: x = 121
  Output: true
  Explanation: 121 reads as 121 from left to right and from right to left.

  Input: x = -121
  Output: false
  Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

  Input: x = 10
  Output: false
  Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Approach:
  - Convert the integer to a string using std::to_string.
  - Use a two-pointer approach: one starting from the front, one from the back.
  - Compare characters while moving inward.
  - If a mismatch is found, return false. If all characters match, return true.

Time Complexity: O(n) — where n is the number of digits in the number
Space Complexity: O(n) — for the string conversion
Tags: Math, String, Two Pointers
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string num = to_string(x);    // convert the integer to a string
        int left = 0;                 // count var beginning with first num
        int right = num.length() - 1; // count var beginning with last num

        // loop until comparisons meet the half point
        while (left < right)
        {
            // check for matching numbers, if there is a mismatch, return false
            if (num[left] != num[right])
            {
                return false;
            }
            left++;  // move count var forward
            right--; // move count var inward
        }

        return true;
    }
};

/*
This version solves the problem without converting the number to a string,
and without using extra space (like an array or vector).

Time Complexity: O(log₁₀(n)) — because we're dividing the number by 10 each loop
Space Complexity: O(1) — constant space
Tags: Math, Two Pointers, Integer Manipulation
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Negative numbers are never palindromes
        // Numbers ending in 0 are not palindromes unless the number is 0 itself
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversed = 0;

        // Reverse half of the number
        while (x > reversed)
        {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // For even-length numbers: x == reversed
        // For odd-length numbers: x == reversed / 10
        return (x == reversed || x == reversed / 10);
    }
};