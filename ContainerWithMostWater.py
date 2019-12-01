#! -*- encoding: utf-8 -*-

'''
11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
'''

'''
思路：
求数组中能使数字组成的矩形面积最大的两个位置
矩形面积由宽和高组成，宽为数组索引的差，高为两位置中较小的数字
不同的位置得到的宽度和高度都不同，所以本题是求两变量条件下的最大值问题

本题中可利用的一个性质，当初始位置分别取在数组两端时，宽度取到了最大值，想在此基础上找最值，只能寻找更高的高度位置，
利用高度弥补宽度的损失，即，从较矮的一端出发，搜索比当前高度高的位置，计算一次面积，再从两位置中较矮的一端出发，循环搜索。

利用极化一个变量，变成单变量优化问题
'''

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        ret = 0
        while left < right:
            h = min(height[left], height[right])
            w = right - left
            area = h * w
            ret = max(ret, area)
            if height[left] < height[right]:
                while height[left] <= h and left < right:
                    left += 1
            else:
                while height[right] <= h and left < right:
                    right -= 1
        return ret
