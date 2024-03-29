"""
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
"""


class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """

        def backtracking(sindex, k, clist):
            if k == 0:
                if sum(clist) == n:
                    rlist.append(clist[:])
                return
            for i in range(sindex, 10):
                if sum(clist) > n:
                    break
                clist.append(i)
                backtracking(i + 1, k - 1, clist)
                clist.pop()

        rlist = []
        tlist = []
        backtracking(1, k, tlist)
        return rlist


if __name__ == '__main__':
    so = Solution()
    so.combinationSum3(3, 7)