# -*- encoding: utf-8 -*-
"""
78
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        res = []
        items = []
        for i in range(1,length+1):
            j = 0
            while True:
                ll = len(items)
                if ll == i:
                    res.append(items[:])
                    items.pop()
                if j >= length:
                    if not items:
                        break
                    j = nums.index(items.pop()) + 1
                else:
                    items.append(nums[j])
                    j += 1
        res.append([])
        return res
so = Solution()
print so.subsets([1,2,3,4])