/*
LeetCode Problem: Fizz Buzz
Link: https://leetcode.com/problems/fizz-buzz/

Given an integer n, return a string array answer (1-indexed) where:
  - answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
  - answer[i] == "Fizz" if i is divisible by 3.
  - answer[i] == "Buzz" if i is divisible by 5.
  - answer[i] == i (as a string) if none of the above conditions are true.

Example 1:
  Input: n = 3
  Output: ["1", "2", "Fizz"]

Example 2:
  Input: n = 5
  Output: ["1", "2", "Fizz", "4", "Buzz"]

Example 3:
  Input: n = 15
  Output: ["1", "2", "Fizz", "4", "Buzz", ..., "14", "FizzBuzz"]

Approach:
  - Loop from 1 to n (inclusive)
  - Use conditionals to check divisibility:
      - If divisible by both 3 and 5 → add "FizzBuzz"
      - Else if divisible by 3 → add "Fizz"
      - Else if divisible by 5 → add "Buzz"
      - Else → convert the integer to a string and add it
  - Use push_back to populate the vector<string> answer
  - Return the final vector<string>

Time Complexity: O(n) — one pass through the range 1 to n
Space Complexity: O(n) — result vector stores n strings
Tags: Array, String, Simulation
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;  // Initialize an empty vector -- stores the final output strings

        // Loop through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");  // Divisible by both 3 and 5
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");      // Divisible by 3 only
            } else if (i % 5 == 0) {
                answer.push_back("Buzz");      // Divisible by 5 only
            } else {
                answer.push_back(to_string(i)); // Not divisible by 3 or 5
            }
        }

        return answer;  // Return the final list of FizzBuzz strings
    }
};