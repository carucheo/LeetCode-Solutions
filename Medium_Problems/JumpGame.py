"""
LeetCode Problem: 55. Jump Game
Link: https://leetcode.com/problems/jump-game/

Problem:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return True if you can reach the last index, or False otherwise.

Example 1:
  Input:  nums = [2,3,1,1,4]
  Output: True

Example 2:
  Input:  nums = [3,2,1,0,4]
  Output: False

Approach:
  - Use a greedy algorithm to track the farthest index we can reach (maxReach).
  - Iterate through each index in the array.
  - If we ever encounter an index greater than maxReach, we cannot reach it — return False.
  - At each step, update maxReach to the farthest we can jump from current position.
  - If the loop completes without returning False, then we can reach the last index.

Time Complexity: O(n) — single pass through the array
Space Complexity: O(1) — constant space
Tags: Array, Greedy
"""

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReach = 0  # Tracks the farthest index we can reach

        for i in range(len(nums)):
            # If current index is beyond the furthest we can jump, we can't proceed
            if i > maxReach:
                return False

            # Update maxReach to the maximum of current max or i + nums[i]
            maxReach = max(maxReach, i + nums[i])

        # If we finish iterating through the list, we can reach the last index
        return True
