#! -*- encoding: utf-8 -*-

'''
34. Find First and Last Position of Element in Sorted Array

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
'''

'''
思路：
相当于求target的左边界和右边界，实现lower_bound和upper_bound
两个找边界方法需要熟练，可以用到很多地方
'''

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1, -1]
        left = self.lower_bound(nums, target)
        right = self.upper_bound(nums, target)
        if target == nums[-1]:
            return [left, right]
        if left == right:
            return [-1, -1]
        return [left, right-1]
        
    def lower_bound(self, nums, target):
        left = 0
        right = len(nums) -  1
        while left < right:
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left
        
    def upper_bound(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid
        return right
