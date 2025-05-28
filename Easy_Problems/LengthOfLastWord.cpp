/*
LeetCode Problem: 58. Length of Last Word
Difficulty: Easy

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Approach:
- Loop from the end of the string
- Skip trailing spaces
- Start counting characters once the last word starts
- Stop counting once a space is reached again (word ends)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                // If we've already started counting, break on the first space
                if (count > 0) break;
                continue; // Still in trailing spaces
            }
            count++; // Count characters in the last word
        }

        return count;
    }
};

// WHILE-loop version
/*
LeetCode Problem: 58. Length of Last Word
Difficulty: Easy

Approach:
- Use two while loops:
    1. Skip trailing spaces
    2. Count characters in the last word
- Return the count of characters in the last word

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;

        // Skip any trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};