"""
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
  - Use append() to build the list

Time Complexity: O(n) — one pass through the range 1 to n
Space Complexity: O(n) — output list stores n strings
Tags: Array, String, Simulation
"""

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = []  # List to store the final FizzBuzz result

        # Loop through numbers from 1 to n (inclusive)
        for i in range(1, n + 1):
            if i % 3 == 0 and i % 5 == 0:
                answer.append("FizzBuzz")  # Divisible by both 3 and 5
            elif i % 3 == 0:
                answer.append("Fizz")      # Divisible by 3 only
            elif i % 5 == 0:
                answer.append("Buzz")      # Divisible by 5 only
            else:
                answer.append(str(i))      # Not divisible by 3 or 5 → add number as string

        return answer  # Return the complete list of FizzBuzz strings
