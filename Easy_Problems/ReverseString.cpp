/*
LeetCode Problem: 344. Reverse String
Link: https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters `s`.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
  Input:  s = ["h", "e", "l", "l", "o"]
  Output: ["o", "l", "l", "e", "h"]

Example 2:
  Input:  s = ["H", "a", "n", "n", "a", "h"]
  Output: ["h", "a", "n", "n", "a", "H"]

Approach:
  - Use the two-pointer technique:
    - One pointer starts from the beginning (`left`)
    - One pointer starts from the end (`right`)
  - Swap the characters at `left` and `right`, then move both inward
  - Repeat until the pointers meet or cross
  - This performs the reversal in-place with constant extra memory

Time Complexity: O(n) — each element is visited once
Space Complexity: O(1) — no additional memory used
Tags: Two Pointers, String, In-Place Modification
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;             // Start pointer at the beginning of the array
        int right = s.size() - 1; // End pointer at the last index

        // Loop until the two pointers meet or cross
        while (left < right)
        {
            swap(s[left], s[right]); // Swap the characters at left and right
            left++;                  // Move left pointer one step to the right
            right--;                 // Move right pointer one step to the left
        }
    }
};

// Code for iterating through 'word' and creating a new reversed string:

#include <iostream>
#include <string>

using namespace std;

string reversedString(string word)
{
    string reversed_word = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        char letter = word[i];
        reversed_word.push_back(letter);
    }

    return reversed_word;
}

int main()
{
    cout << reversedString("lalo") << endl;

    return 0;
}