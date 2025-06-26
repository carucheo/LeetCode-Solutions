"""
LeetCode Problem: 268. Missing Number
Link: https://leetcode.com/problems/missing-number/

Problem:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Example 1:
  Input: nums = [3,0,1]
  Output: 2

Example 2:
  Input: nums = [0,1]
  Output: 2

Example 3:
  Input: nums = [9,6,4,2,3,5,7,0,1]
  Output: 8

Approach:
  - Insert all numbers from nums into a set for O(1) lookups.
  - Iterate from 0 to n (inclusive) and check which number is not in the set.
  - Return the number that is missing.
  - Return -1 as a fallback, though the problem guarantees a missing number exists.

Time Complexity: O(n) — One pass to build the set, and one pass to check the range
Space Complexity: O(n) — For the extra set storing all elements
Tags: Array, Hash Set, Math
"""

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        numSet = set(nums)  # Convert the list to a set for fast lookup

        # Loop through all numbers from 0 to n (inclusive)
        for i in range(len(nums) + 1):
            if i not in numSet:  # If the number is missing from the set
                return i         # Return the missing number

        # Fallback
        return -1