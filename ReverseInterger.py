#! -*- encoding: utf-8 -*-

'''
Reverse Integer

Share
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
'''

'''
思路：
首先从低位开始，获得每个位置上的数字，得到全部数字后整体数字的长度也可得到
低位数字依次乘以高位数字的10幂方
不要忘记符号
不要忘记仅限32位数字
'''

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        xs = str(x)
        sig = -1 if xs[0] == '-' else 1
        xs = xs if sig == 1 else xs[1:]
        leng = len(xs)
        nums = 0
        for i in range(leng-1, -1, -1):
            nums += int(xs[i]) * (10 ** i)
        nums = nums * sig
        if nums < (-2) ** 31 or nums > (2 ** 31 -1):
            return 0
        return nums
