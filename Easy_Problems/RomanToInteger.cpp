/*
LeetCode Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Roman numerals are represented by seven symbols: I (1), V (5), X (10), L (50),
C (100), D (500), and M (1000). Normally, numerals are written from largest
to smallest left to right, but there are six known subtractive combinations:

  - I before V (5) or X (10) → 4, 9
  - X before L (50) or C (100) → 40, 90
  - C before D (500) or M (1000) → 400, 900

Given a string s representing a Roman numeral, convert it to its integer value.

Example 1:
  Input: s = "III"
  Output: 3

Example 2:
  Input: s = "LVIII"
  Output: 58

Example 3:
  Input: s = "MCMXCIV"
  Output: 1994

Approach:
  - Use a map to associate Roman characters to integer values
  - Traverse the string from left to right using a while loop
  - Check for subtractive cases by comparing current and next character
  - If a subtractive pair is found, subtract and skip both characters
  - Otherwise, add the value of the current character
  - Accumulate the total into the result and return

Time Complexity: O(n) — n is the length of the string
Space Complexity: O(1) — constant extra space for the map
Tags: String, HashMap, Greedy, Simulation
*/

class Solution {
public:
    int romanToInt(string s) {
        // Mapping Roman numerals to their corresponding integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;  // Accumulator for final integer result
        int i = 0;       // Index to traverse the string

        while (i < s.length()) {
            // Check if current and next character form a subtractive pair
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                // Subtractive case: e.g., IV → 5 - 1 = 4
                result += roman[s[i + 1]] - roman[s[i]];
                i += 2;  // Skip the pair
            } else {
                // Regular case: just add the current value
                result += roman[s[i]];
                i += 1;  // Move to the next character
            }
        }

        return result;  // Return the total computed value
    }
};