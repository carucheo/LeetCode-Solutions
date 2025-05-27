/*
LeetCode Problem: Remove Element
Link: https://leetcode.com/problems/remove-element/

Given an integer array nums and an integer val, remove all occurrences of val
in-place. The order of elements may change. Then return the number of elements
not equal to val.

The first k elements of nums should contain the valid result. The rest of the
array beyond k does not matter.

Examples:
  Input:  nums = [3,2,2,3], val = 3
  Output: 2  → nums = [2,2,_,_]

  Input:  nums = [0,1,2,2,3,0,4,2], val = 2
  Output: 5  → nums = [0,1,4,0,3,_,_,_]

Approach:
  - Use a write pointer `k` to track where the next non-val element should go
  - Iterate over the array, and for each element not equal to val:
      - Overwrite nums[k] with that element
      - Increment k
  - At the end, nums[0..k-1] contains all valid elements

Time Complexity: O(n) — single pass through the array
Space Complexity: O(1) — in-place with no extra space
Tags: Array, Two Pointers, In-Place
*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0; // index for placing next valid element

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i]; // overwrite with valid element
                k++;
            }
        }
        
        return k; // number of elements not equal to val
    }
};
