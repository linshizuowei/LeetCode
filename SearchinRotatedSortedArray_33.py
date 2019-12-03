#! -*- encoding: utf-8 -*-

'''
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
'''

'''
思路：
有序数组被旋转了，相当于数组中有两个子有序数组，再使用二分查找时需要注意细节
主要是mid指针和target分别位于哪个子数组中，及他们的大小关系，边界点也要注意
'''

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        right = len(nums) - 1
        left = 0
        
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[left] <= nums[mid]:
                if target <= nums[mid] and target >= nums[left]:
                    right = mid-1
                else:
                    left = mid + 1
            else:
                if target >= nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
