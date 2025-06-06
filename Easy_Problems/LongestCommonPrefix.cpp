/*
LeetCode Problem: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/

Problem:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example:
  Input:  strs = ["flower","flow","flight"]
  Output: "fl"

Approach:
  - Use the first string as an initial candidate for the prefix.
  - Compare this prefix with each string in the array.
  - If the current string does not start with the prefix, trim the last character from the prefix.
  - Repeat trimming until the prefix matches the beginning of the current string.
  - Stop early and return "" if the prefix becomes empty.

Time Complexity: O(S), where S is the sum of all characters in all strings
Space Complexity: O(1) — we reuse the input and only keep a small prefix string
Tags: String, Prefix, Iterative
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Edge case: if the input vector is empty, return an empty string
        if (strs.empty())
            return "";

        // Start by assuming the entire first string is the common prefix
        string prefix = strs[0];

        // Iterate through the rest of the strings
        for (int i = 1; i < strs.size(); ++i)
        {
            // While the current string doesn't start with the prefix
            while (strs[i].find(prefix) != 0)
            {
                // Trim the last character from the prefix
                prefix = prefix.substr(0, prefix.length() - 1);

                // If prefix becomes empty, there is no common prefix
                if (prefix.empty())
                    return "";
            }
        }

        // Return the longest common prefix after checking all strings
        return prefix;
    }
};