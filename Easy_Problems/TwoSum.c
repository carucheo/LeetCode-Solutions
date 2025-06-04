/**
 * LeetCode Problem: Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target,
 * return the indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example:
 *   Input: nums = [2, 7, 11, 15], target = 9
 *   Output: [0, 1]
 *   Explanation: Because nums[0] + nums[1] == 9
 *
 * Approach:
 *   - Use a brute-force nested loop to check all pairs of indices.
 *   - If a pair adds up to the target, allocate an array of size 2 on the heap.
 *   - Store the indices in the array and return it.
 *   - Set *returnSize = 2 to indicate the result array length.
 *
 * Time Complexity: O(n^2) — compares all pairs
 * Space Complexity: O(1) — only uses space for result (constant size)
 * Language Notes:
 *   - In C, we must explicitly allocate memory with malloc and return a pointer.
 *   - Arrays are not returnable by value in C like they are in C++.
 *   - Use `result[0]` and `result[1]` via pointer arithmetic — `result` is a pointer.
 *   - Must also manually set *returnSize.
 */

 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Brute-force approach: check all unique pairs
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                // Allocate space for 2 integers on the heap
                int* result = (int*)malloc(2 * sizeof(int));

                // In C, we assign values using array-like syntax on the pointer
                // result[0] = i assigns the first index
                // result[1] = j assigns the second index
                result[0] = i;
                result[1] = j;

                // Set the returnSize pointer to 2
                *returnSize = 2;

                return result;
            }
        }
    }

    // Return NULL if no solution found (though the problem guarantees one)
    *returnSize = 0;
    return NULL;
}