"""
LeetCode Problem: Jewels and Stones
Link: https://leetcode.com/problems/jewels-and-stones/

You're given strings `jewels` and `stones`. Each character in `stones` represents a stone you have.
Each character in `jewels` represents a type of stone that is a jewel.
Return the number of stones that are also jewels.

Letters are case-sensitive, so "a" and "A" are considered different.

Examples:
  Input: jewels = "aA", stones = "aAAbbbb"
  Output: 3

  Input: jewels = "z", stones = "ZZ"
  Output: 0

Approach:
  - Add each character from `jewels` to a set for O(1) lookup
  - Iterate through `stones` and count how many are in the set

Time Complexity: O(n + m) — n = len(jewels), m = len(stones)
Space Complexity: O(n) — for storing the jewel set
Tags: Hash Set, String, Counting
"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewelSet = set()
        count = 0

        # Add each jewel type to the set
        for ch in jewels:
            jewelSet.add(ch)

        # Count stones that are jewels
        for ch in stones:
            if ch in jewelSet:
                count += 1

        return count
