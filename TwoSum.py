"""
LeetCode Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target,
return the indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.

Example:
  Input: nums = [2, 7, 11, 15], target = 9
  Output: [0, 1]
  Explanation: Because nums[0] + nums[1] == 9

Approach:
  - Use two nested loops (brute-force approach)
  - For each pair (i, j), check if nums[i] + nums[j] == target
  - Return [i, j] immediately when a match is found

Time Complexity: O(n^2) — checks all pairs in worst case
Space Complexity: O(1) — no extra space used
Tags: Array, Brute Force
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)): 
                if (nums[i] + nums[j] == target):
                    return [i, j]