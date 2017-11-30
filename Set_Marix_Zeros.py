# -*- encding: utf-8 -*-
"""
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
"""
"""
用原矩阵的第一行和第一列记录对应的列和行中是否出现了0，又因为matrix[0][0]既在第一行又在第一列，所以使用一个额外的
变量记录第一列的情况，matrix[0][0]只记录第一行的情况。
二次循环时倒序循环，把第一行和第一列的判断留到最后，避免影响其他行列。
"""
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        col0 = 1
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                col0 = 0
            for j in range(1, len(matrix[i])):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(len(matrix)-1, -1, -1):
            for j in range(len(matrix[i])-1, 0, -1):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if col0 == 0:
                matrix[i][0] = 0
        print matrix
so = Solution()
so.setZeroes([[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]])