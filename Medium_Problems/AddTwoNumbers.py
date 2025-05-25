"""
LeetCode Problem: Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return the result as a linked list.

Example:
  Input: l1 = [2,4,3], l2 = [5,6,4]
  Output: [7,0,8] (342 + 465 = 807)

Approach:
  - Use a dummy head node to simplify list construction.
  - Loop through both lists until both are fully processed and there's no carry left.
  - At each step, add values from both lists and any carry.
  - Create a new node for the resulting digit and link it to the result list.
  - If there's a carry after the loop, add a final node.

Time Complexity: O(max(n, m)) — where n and m are the lengths of the input lists
Space Complexity: O(max(n, m)) — for storing the result list
Tags: Linked List, Math, Simulation
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        current = dummy_head
        carry = 0

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry
            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy_head.next