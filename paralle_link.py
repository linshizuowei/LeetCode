# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
        cur = head
        cnt = 0
        while cur:
            cnt += 1
            cur = cur.next
        cur = head
        net = head.next
        for i in range(1, cnt // 2):
            tmp = net.next
            net.next = cur
            cur = net
            net = tmp
        if cnt % 2 != 0:
            net = net.next

        while net:
            if net.val != cur.val:
                return False
            net = net.next
            cur = cur.next
        return True


if __name__ == '__main__':
    head = ListNode(1)
    net = ListNode(2)
    head.next = net
    so = Solution()
    so.isPalindrome(head)