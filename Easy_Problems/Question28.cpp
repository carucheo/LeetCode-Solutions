/*
LeetCode Problem: 28. Find the Index of the First Occurrence in a String
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Description:
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

Examples:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Input: haystack = "leetcode", needle = "leeto"
Output: -1

Approach:
- Iterate over all possible starting positions in haystack where needle could match
- For each position, check if all characters in needle match the corresponding characters in haystack
- If a full match is found, return the starting index
- If no match is found after the loop, return -1

Time Complexity: O(n * m), where n is the length of haystack and m is the length of needle
Space Complexity: O(1)
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // Exit early if needle is longer than haystack
        if (needle.length() > haystack.length())
        {
            return -1;
        }

        // Loop through each valid starting position in haystack
        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            int j;
            // Check if needle matches starting at position i
            for (j = 0; j < needle.length(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break; // Mismatch found, exit inner loop early
                }
            }

            // If we completed the inner loop, a full match was found
            if (j == needle.length())
            {
                return i;
            }
        }
        // No match found
        return -1;
    }
};
