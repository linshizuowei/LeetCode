#! -*- ecoding: utf-8 -*-

'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
'''

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


'''
思路：
列表方式作加法，按位加即可，思路直观，主要问题在于向前进位的处理
case: [5], [5]   ---->   [0,1];   [5], [5, 9, 9]   ---->  [0, 0, 0, 1]
当前节点值val是由三个数决定的：list1.val, list2.val, 上一位是否进位（0， 1）
而且，三数相加得val后也要看val是否>10,从而需要进位
'''

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        sig = 0
        head = ListNode(None)
        pre = head
        while l1 or l2 or sig:
            v1 = 0
            v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            ret = v1 + v2 + sig
            num = ret if ret < 10 else ret - 10
            sig = 0 if ret < 10 else 1
            node = ListNode(num)
            pre.next = node
            pre = pre.next
        return head.next
