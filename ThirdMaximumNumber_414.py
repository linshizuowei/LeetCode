#! -*- encoding: utf-8 -*-

'''
414. Third Maximum Number

Share
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
'''

'''
思路：
要求log(n)复杂度，使用三指针的方式，每个元素比较三次，log(3n) == log(n)
'''

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first = None
        second = None
        third = None
        for i in nums:
            first, second, third = self.sort(first, second, third, i)
        if third == None:
            return first
        else:
            return third
            
    def sort(self, first, second, third, num):
        if first == None:
            first = num
        elif second == None:
            if first > num:
                second = num
            elif first < num:
                second = first
                first = num
        elif third == None:
            if num != first and num != second:
                first, second, third = sorted([first, second, num], reverse=True)
        else:
            if num != first and num != second and num != third:
                first, second, third = sorted([first, second, third, num], reverse=True)[:3]
        return first, second, third
