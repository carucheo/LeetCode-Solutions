"""
LeetCode Problem: Remove Element
Link: https://leetcode.com/problems/remove-element/

Given an integer array nums and an integer val, remove all occurrences of val in-place.
Return the number of elements that are not equal to val.

You must modify the input list in-place and return the new length (k).
The elements beyond the first k positions do not matter.

Examples:
  Input: nums = [3,2,2,3], val = 3
  Output: 2 → nums becomes [2,2,_,_]

  Input: nums = [0,1,2,2,3,0,4,2], val = 2
  Output: 5 → nums becomes [0,1,4,0,3,_,_,_]

Approach:
  - Use a write index (k) to track where the next valid (non-val) element should go.
  - Loop through each number in nums.
  - If the number is not equal to val, place it at nums[k], and increment k.
  - At the end, nums[:k] contains all valid elements.

Time Complexity: O(n) — one pass through the list
Space Complexity: O(1) — in-place, no extra memory
Tags: Array, Two Pointers, In-Place Modification
"""

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0  # write pointer

        for num in nums:
            if num != val:
                nums[k] = num  # overwrite in-place
                k += 1

        return k  # number of valid elements
