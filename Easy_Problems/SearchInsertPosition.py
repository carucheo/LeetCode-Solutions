"""
LeetCode Problem: Search Insert Position  
Link: https://leetcode.com/problems/search-insert-position/

Problem:
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

Examples:
  Input: nums = [1, 3, 5, 6], target = 5
  Output: 2

  Input: nums = [1, 3, 5, 6], target = 2
  Output: 1

  Input: nums = [1, 3, 5, 6], target = 7
  Output: 4

Approach:
  - Use binary search to achieve O(log n) runtime.
  - Maintain two pointers: left and right to represent the search boundaries.
  - Calculate mid = left + (right - left) // 2 to avoid overflow.
  - If nums[mid] == target, return mid.
  - If nums[mid] < target, move left to mid + 1 to search right half.
  - If nums[mid] > target, move right to mid - 1 to search left half.
  - If target is not found, left will be the correct insertion index.

Time Complexity: O(log n) — binary search
Space Complexity: O(1) — constant extra space
Tags: Array, Binary Search
"""

from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # Initialize left boundary for binary search
        left = 0
        # Initialize right boundary for binary search
        right = len(nums) - 1

        # Loop until left and right pointers cross
        while left <= right:
            # Calculate mid to avoid potential overflow
            mid = left + (right - left) // 2

            # Check if mid element is the target
            if nums[mid] == target:
                return mid

            # If mid element is less than target, search in the right half
            elif nums[mid] < target:
                left = mid + 1

            # If mid element is greater than target, search in the left half
            else:
                right = mid - 1

        # If target not found, left is the insert position
        return left
