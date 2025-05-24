/*
LeetCode Problem: Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return the result as a linked list.

Input:
  l1 = [2,4,3]
  l2 = [5,6,4]

Output:
  [7,0,8]

Explanation:
  342 + 465 = 807

Approach:
  - Use a dummy head to simplify result list construction.
  - Traverse both lists digit by digit, adding values and tracking carry.
  - Handle different list lengths by treating missing nodes as 0.
  - Create new nodes for each digit of the result.
  - If there's a carry left after both lists are processed, append it.

Time Complexity: O(max(n, m)) — where n and m are the lengths of the input lists
Space Complexity: O(max(n, m)) — for storing the result list
Tags: Linked List, Math, Simulation
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head simplifies list construction
        ListNode* dummy_head = new ListNode();
        ListNode* current = dummy_head; // Tracks the end of the result list
        int carry = 0;                  // Holds carry from each digit addition

        // Loop until both lists are fully processed and there's no carry left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from current nodes, or use 0 if a list is shorter
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate sum of current digits and carry
            int sum = val1 + val2 + carry;
            int digit = sum % 10;      // Digit to store in new node
            carry = sum / 10;          // Carry to use in next iteration

            // Create new node with the digit and link it to the result list
            current->next = new ListNode(digit);
            current = current->next;   // Advance to the new tail

            // Move to the next nodes in each input list (if they exist)
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the real start of the result list (skipping dummy head because that is 0)
        return dummy_head->next;
    }
};