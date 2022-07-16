#! -*- encoding: utf-8 -*-

'''
581. Shortest Unsorted Continuous Subarray

Share
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
'''

'''
思路：
先找到需要排序的子数组左右边界，方式是左边找第一个小于其左邻接点的索引，右边找第一个大于其右邻接点的索引
然后在子数组中找到最大值和最小值
分别为最小/最大值在剩余左边数组和右边数组寻找排序位置，找到的位置之间的部分就是需要排序的最终子数组
时间复杂度log（n)
'''

class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = None
        right = None
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                left = i
                break
        for i in range(len(nums)-1, 0, -1):
            if nums[i] < nums[i-1]:
                right = i
                break
        if left == None or right == None:
            return 0
        mi = min(nums[left:right+1])
        ma = max(nums[left:right+1])
        
        for i in range(left+1):
            if nums[i] > mi:
                start = i
                break
        end = len(nums)
        for i in range(right, len(nums)):
            if nums[i] >= ma:
                end = i
                break
        return end - start
