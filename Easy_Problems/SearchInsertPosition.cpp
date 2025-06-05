/*
LeetCode Problem: Search Insert Position  
Link: https://leetcode.com/problems/search-insert-position/

Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Examples:
  Input: nums = [1, 3, 5, 6], target = 5
  Output: 2

  Input: nums = [1, 3, 5, 6], target = 2
  Output: 1

  Input: nums = [1, 3, 5, 6], target = 7
  Output: 4

Approach:
  - Use binary search to achieve O(log n) runtime
  - Maintain two pointers: left and right
  - Calculate mid = left + (right - left) / 2
  - If nums[mid] == target, return mid
  - If nums[mid] < target, search in right half (left = mid + 1)
  - If nums[mid] > target, search in left half (right = mid - 1)
  - If target is not found, return left as the insert position

Time Complexity: O(log n) — binary search
Space Complexity: O(1) — constant extra space
Tags: Array, Binary Search
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;                      // Initialize the left boundary of search
        int right = nums.size() - 1;       // Initialize the right boundary of search

        // Perform binary search
        while (left <= right) {
            // Calculate the midpoint safely to prevent potential overflow
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;                // Target found, return index
            } else if (nums[mid] < target) {
                left = mid + 1;            // Target is in the right half
            } else {
                right = mid - 1;           // Target is in the left half
            }
        }

        // If not found, 'left' points to the correct insertion position
        return left;
    }
};