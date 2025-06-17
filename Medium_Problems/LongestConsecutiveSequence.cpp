/*
LeetCode Problem: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Problem:
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.
Your algorithm must run in O(n) time.

Example 1:
  Input:  nums = [100,4,200,1,3,2]
  Output: 4
  Explanation: The longest consecutive sequence is [1,2,3,4].

Example 2:
  Input:  nums = [0,3,7,2,5,8,4,6,0,1]
  Output: 9

Approach:
  - Insert all numbers into an unordered_set for O(1) lookups.
  - For each number, check if it's the start of a sequence by verifying (num - 1) is not in the set.
  - If it is the start, count how long the consecutive sequence continues by checking subsequent numbers.
  - Keep track of the longest consecutive sequence length found.
  - Return the longest length after processing all numbers.

Time Complexity: O(n) — Each number is processed at most twice
Space Complexity: O(n) — Space for the unordered_set
Tags: Array, Hash Set, Hash Table
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Stores all numbers for fast lookup
        unordered_set<int> numSet;

        // Populate the set with all numbers from the array
        for (int i = 0; i < nums.size(); i++)
        {
            numSet.insert(nums[i]);
        }

        int longest = 0; // Tracks the longest consecutive sequence found

        // Iterate through each number in the original array
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            // Only start counting if 'num' is the beginning of a sequence
            if (numSet.count(num - 1) == 0)
            {
                int currentNum = num;
                int currentStreak = 1;

                // Count consecutive numbers after 'num'
                while (numSet.count(currentNum + 1) == 1)
                {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found so far
                longest = max(longest, currentStreak);
            }
        }

        return longest; // Return the length of the longest consecutive sequence
    }
};