/*
LeetCode Problem: Jewels and Stones
Link: https://leetcode.com/problems/jewels-and-stones/

You're given two strings: `jewels` (representing types of jewels) and `stones`
(representing the stones you have). Each character in `stones` is a type of
stone, and you want to count how many are jewels.

Letters are case-sensitive. All characters in `jewels` are guaranteed unique.

Examples:
  Input:  jewels = "aA", stones = "aAAbbbb"
  Output: 3  → (a, A, A)

  Input:  jewels = "z", stones = "ZZ"
  Output: 0

Approach:
  - Store each jewel type in a set for O(1) lookups.
  - Loop through each character in `stones` and increment a counter
    whenever that stone is also in the set.

Time Complexity: O(m + n) — m = length of jewels, n = length of stones
Space Complexity: O(m) — for storing jewel types
Tags: Hash Table, String, Set, Frequency Count
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> jewelSet;
        int count = 0;

        // Populate set with jewel types
        for (int i = 0; i < jewels.length(); i++) {
            jewelSet.insert(jewels[i]);
        }

        // Count how many stones are jewels
        for (int i = 0; i < stones.length(); i++) {
            if (jewelSet.count(stones[i])) {
                count++;
            }
        }

        return count;
    }
};