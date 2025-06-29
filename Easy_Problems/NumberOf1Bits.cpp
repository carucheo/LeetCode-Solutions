/*
LeetCode Problem: 191. Number of 1 Bits
Link: https://leetcode.com/problems/number-of-1-bits/

Problem:
Given an unsigned integer `n`, return the number of '1' bits it has (also known as the Hamming weight).

Example 1:
  Input:  n = 11
  Output: 3
  Explanation: Binary representation is 1011, which has three 1s.

Example 2:
  Input:  n = 128
  Output: 1
  Explanation: Binary representation is 10000000, which has one 1.

Example 3:
  Input:  n = 2147483645
  Output: 30
  Explanation: Binary representation has thirty 1s.

Approach:
  - Use bitwise operations to efficiently count set bits.
  - Repeatedly check if the least significant bit (LSB) is 1 using (n & 1).
  - Right-shift the number to move through all its bits.
  - Count how many times a 1 is encountered.
  - Alternative to (n & 1) is (n % 2 != 0), and shifting can also be done with (n = n / 2).

Time Complexity: O(32) — constant time, as n is a 32-bit integer
Space Complexity: O(1) — no extra space used
Tags: Bit Manipulation
*/

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0; // Initialize the count of 1s

        // Loop until all bits are shifted out
        while (n != 0)
        {
            // Alternative use (n % 2 != 0) instead of bitwise AND (n & 1)
            if (n & 1)
            {            // Check if the least significant bit is 1
                count++; // If so, increment the count
            }

            n = n >> 1; // Shift bits to the right to check the next bit
            // Alternative: use (n = n / 2) instead of bit shift
        }

        return count; // Return the total number of 1s
    }
};
