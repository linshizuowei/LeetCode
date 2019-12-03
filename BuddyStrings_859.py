#! -*- encoding: utf-8 -*-

'''
859. Buddy Strings

Share
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
'''

'''
思路：
字符串在两种情况下有可能符合条件
1，两字符串的不同字符数为2
这种情况下需要进一步验证有差异的字符是否在交换后符合条件
2，两字符串的不同字符数为0
这种情况下字符串中必须有重复字符才行
'''

class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        cnt = 0
        diffa = []
        diffb = []
        for i in range(len(A)):
            if A[i] != B[i]:
                cnt += 1
                diffa.append(A[i])
                diffb.append(B[i])
        if cnt == 2 and diffa[0] == diffb[1] and diffa[1] == diffb[0]:
            return True
        elif cnt == 0 and len(set(A)) != len(A):
            return True
        else:
            return False
