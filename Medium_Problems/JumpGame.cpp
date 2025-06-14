/*
LeetCode Problem: 55. Jump Game
Link: https://leetcode.com/problems/jump-game/

Problem:
You are given an integer array nums. Each element represents your maximum jump length at that position.
Determine if you can reach the last index starting from the first.

Example 1:
  Input:  nums = [2,3,1,1,4]
  Output: true
  Explanation: Jump from index 0 to 1, then from index 1 to 4.

Example 2:
  Input:  nums = [3,2,1,0,4]
  Output: false
  Explanation: You will get stuck at index 3.

Approach:
  - Use a greedy strategy to track the farthest index you can reach (`maxReach`).
  - Iterate through the array.
  - If at any point the current index is beyond `maxReach`, return false.
  - Continuously update `maxReach` with the furthest we can reach from each index.
  - If the loop finishes, that means we were able to traverse the array safely.

Time Complexity: O(n) — single pass through the array
Space Complexity: O(1) — constant extra space
Tags: Array, Greedy
*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0; // Tracks the farthest index we can reach

        for (int i = 0; i < nums.size(); ++i)
        {
            // If our current index is beyond the furthest reachable point, we can't proceed
            if (i > maxReach)
            {
                return false;
            }

            // Update maxReach if we can jump farther from the current index
            maxReach = max(maxReach, i + nums[i]);
        }

        // If we've made it through the loop, we can reach the last index
        return true;
    }
};