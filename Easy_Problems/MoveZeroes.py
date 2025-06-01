"""
LeetCode Problem: Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

You must do this in-place without making a copy of the array.

Example 1:
  Input: nums = [0, 1, 0, 3, 12]
  Output: [1, 3, 12, 0, 0]

Example 2:
  Input: nums = [0]
  Output: [0]

Approach:
  - Use two pointers: left and right
  - right scans each element in the array
  - When a non-zero element is found at right, swap it with the value at left
  - Increment left only when a non-zero is placed
  - Always increment right to progress through the list
  - This places all non-zero elements in their original order at the front,
    and pushes all zeroes to the end

Time Complexity: O(n) — traverses the array once
Space Complexity: O(1) — in-place, no extra memory used
Tags: Array, Two Pointers, In-Place
"""

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0   # Points to the position where the next non-zero should go
        right = 0  # Scans through the entire array

        # Loop until right pointer reaches the end of the array
        while right < len(nums):
            if nums[right] != 0:
                # Swap non-zero element at right with the element at left
                nums[left], nums[right] = nums[right], nums[left]
                left += 1  # Move left forward to the next insert position
            # Always move right forward to continue scanning
            right += 1
