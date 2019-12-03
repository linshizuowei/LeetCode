#! -*- encoding: utf-8 -*-

'''
41. First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
'''

'''
思路：
只关心正整数，所以数组内的负数和0都可以忽略，它们所在的位置也可以作他用
将数组内正整数挪到nums[nums[i]-1]的位置上，然后遍历数组，当位置i上的数不是i+1时，该位置即为缺失数字位置
要注意在挪动数字时，需要将没在正确位置的数字连续挪动，使用while循环
'''


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[i] != nums[nums[i]-1]:   ### 连续挪动
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums) + 1

so = Solution()
so.firstMissingPositive([3,4,-1,1])
