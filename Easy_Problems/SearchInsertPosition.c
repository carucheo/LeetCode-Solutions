/*
LeetCode Problem: Search Insert Position
Link: https://leetcode.com/problems/search-insert-position/

Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index 
where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example:
  Input: nums = [1, 3, 5, 6], target = 5
  Output: 2

  Input: nums = [1, 3, 5, 6], target = 2
  Output: 1

  Input: nums = [1, 3, 5, 6], target = 7
  Output: 4

Approach:
  - Use binary search to find the target in O(log n) time.
  - Maintain two pointers: `left` and `right` to represent the current search bounds.
  - On each iteration:
      - Calculate `mid` as the midpoint of `left` and `right`.
      - If the target equals `nums[mid]`, return `mid`.
      - If target is greater, move `left` to `mid + 1`.
      - If target is smaller, move `right` to `mid - 1`.
  - If target is not found, `left` will be the correct insert position.

Time Complexity: O(log n) — binary search
Space Complexity: O(1) — constant space
Tags: Array, Binary Search
*/

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    // Perform binary search
    while (left <= right) {
        // Prevents potential overflow
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            // Found the target at index mid
            return mid;
        } else if (nums[mid] < target) {
            // Target is in the right half
            left = mid + 1;
        } else {
            // Target is in the left half
            right = mid - 1;
        }
    }

    // Target was not found, return the insertion index
    return left;
}