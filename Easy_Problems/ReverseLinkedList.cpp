/*
LeetCode Problem: 206. Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

Problem:
Given the head of a singly linked list, reverse the list and return the new head.

Example 1:
  Input:  head = [1,2,3,4,5]
  Output: [5,4,3,2,1]

Example 2:
  Input:  head = [1,2]
  Output: [2,1]

Example 3:
  Input:  head = []
  Output: []

Approach:
  - Use three pointers: prev, curr, and next.
  - Traverse the list, and at each step, reverse the direction of the link.
  - Move prev and curr one step forward.
  - When curr becomes null, prev will be the new head of the reversed list.

Time Complexity: O(n) — where n is the number of nodes in the list
Space Complexity: O(1) — in-place reversal with constant extra space
Tags: Linked List, Two Pointers
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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr; // Previous node starts as null
        ListNode *curr = head;    // Current node starts at head

        // Traverse the list
        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next; // Save next node before breaking the link
            curr->next = prev;               // Reverse the current node's pointer
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }

        return prev; // prev is now the new head of the reversed list
    }
};
