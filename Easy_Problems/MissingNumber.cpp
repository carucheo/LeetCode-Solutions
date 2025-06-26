/*
LeetCode Problem: 268. Missing Number
Link: https://leetcode.com/problems/missing-number/

Problem:
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

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
  - Insert all numbers from nums into an unordered_set for O(1) lookups.
  - Iterate from 0 to n (inclusive), checking which number is not in the set.
  - Return the number that is missing.
  - The return -1 is a fallback that should never be reached if the input constraints are met.

Time Complexity: O(n) — Single pass to build set, single pass to find missing number
Space Complexity: O(n) — Space used by unordered_set
Tags: Array, Hash Set
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Create a set containing all numbers in nums for O(1) membership checks
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Check for the missing number in the full range [0, n]
        for (int i = 0; i <= nums.size(); i++) {
            if (numSet.count(i) == 0) {  // If i is not found in the set
                return i;                 // Return i as the missing number
            }
        }

        // Fallback return -1
        return -1;
    }
};