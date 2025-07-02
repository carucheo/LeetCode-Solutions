"""
LeetCode Problem: 191. Number of 1 Bits
Link: https://leetcode.com/problems/number-of-1-bits/

Problem:
Write a function that takes an unsigned integer and returns the number of '1' bits it has 
(also known as the Hamming weight).

Example 1:
  Input:  n = 11
  Output: 3
  Explanation: Binary representation is 1011, which has three 1s.

Example 2:
  Input:  n = 128
  Output: 1
  Explanation: Binary is 10000000

Example 3:
  Input:  n = 2147483645
  Output: 30

Approach:
  - Use bitwise operations to efficiently check each bit.
  - Repeatedly check if the least significant bit (LSB) is 1 using (n & 1).
  - Shift bits to the right to move to the next position.
  - Count how many times a 1 appears in the binary representation.
  - Alternative: you could use (n % 2) and (n // 2), but bitwise ops are faster.

Time Complexity: O(32) — constant time for 32-bit integers
Space Complexity: O(1) — no extra memory used
Tags: Bit Manipulation
"""

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0  # Initialize count of 1s

        # Iterate while n is not zero. Alternative use (n % 2 != 0) instead of bitwise AND (n & 1)
        while n != 0:
            if n & 1:         # Check if the least significant bit is 1
                count += 1    # If so, increment the count
            
            n = n >> 1        # Shift bits to the right to process the next bit
            # Alternative: use n = n // 2 (less efficient for bitwise tasks)

        return count  # Return the total number of 1 bits