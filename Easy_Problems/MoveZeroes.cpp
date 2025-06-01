/*
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
  - When nums[right] is non-zero, swap it with nums[left]
  - Move left forward whenever a non-zero is found
  - This ensures all non-zero elements are moved to the front
    in their original order and all zeros are pushed to the back

Time Complexity: O(n) — traverse the array once
Space Complexity: O(1) — in-place operation, no extra memory used
Tags: Array, Two Pointers, In-Place
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // Position to move the next non-zero element to
        int right = 0; // Current index in the array

        // Traverse the array with the right pointer
        while (right < nums.size()) {
            if (nums[right] != 0) {
                // Swap current element with the left pointer position
                swap(nums[right], nums[left]);
                left++;  // Move left pointer forward for next non-zero
            }
            right++;  // Always move the right pointer forward
        }
    }
};