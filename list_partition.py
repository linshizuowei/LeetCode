# -*- coding: utf-8 -*-

import random
"""
题目描述
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
"""
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Partition:
    def partition(self, pHead, x):
        # write code here
        s = s_head = ListNode(x)
        b = b_head = ListNode(x)

        while pHead != None:
            if pHead.val < x:
                s.next = pHead
                s = s.next

            if pHead.val >= x:
                b.next = pHead
                b = b.next

            pHead = pHead.next
        b.next = None
        s.next = b_head.next
        return s_head.next

# if __name__ == '__main__':
#     head = ListNode(-1)
#     p = head
#     for i in range(5):
#         t = ListNode(random.randint(1,100))
#         head.next = t
#         head = head.next
#         print head.val
#     print '---------------------'
#     pa = Partition()
#     ll = pa.partition(p.next, 50)
#     s = 5
#     while ll != None:
#         s -= 1
#         print ll.val
#         ll = ll.next
#         # if s < 1:
#         #     break