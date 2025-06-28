"""
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
  - Traverse the list, and at each step, reverse the direction of the current node's pointer.
  - Move prev and curr one step forward.
  - When curr becomes None, prev will be pointing at the new head of the reversed list.

Time Complexity: O(n) — Traverse each node once
Space Complexity: O(1) — In-place reversal
Tags: Linked List, Two Pointers, Iterative
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None         # Initially, there's no previous node
        curr = head         # Start traversal from the head

        # Iterate through the list and reverse pointers
        while curr:
            nextNode = curr.next     # Save the next node before changing the pointer
            curr.next = prev         # Reverse the current node's next pointer
            prev = curr              # Move prev to the current node
            curr = nextNode          # Move to the next node in the list

        return prev         # prev is the new head of the reversed list
