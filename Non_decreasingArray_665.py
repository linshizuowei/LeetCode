#! -*- encoding: utf-8 -*-

'''
665. Non-decreasing Array

Share
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
'''

'''
思路：
最多修改一个元素使数组变成非降序数组，意味着数组中最多只能有一个极小值点，且极小值点的左邻接点是左半部分的极大值，又邻接点事有半部分的极小值，这种情况下才有可能变成非降序数组
sig标识是否已找到极小值点
极小值唯一的情况下，可以调整左邻接点或者极小值点来变成非降序数组
左邻接点要么是0位置，要么极小值点不小于左邻接点的左边元素，这样左邻接点才有调整的空间
右邻接点要么是末尾位置，要么不小于左邻接点，这样极小值点才有调整空间
'''

class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 1:
            return True
        sig = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if sig == 1:
                    return False
                if i == 1 or nums[i] - nums[i-2] >= 0 or i == len(nums)-1 or nums[i+1] >= nums[i-1]:
                    sig = 1
                else:
                    return False
        return True
