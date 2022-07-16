"""
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

cnt = 0


class Solution(object):
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """

        def dfs(node, clist, pre_sum):
            global cnt
            if node is None:
                return
            clist.append(node.val)
            pre_sum = [x + node.val for x in pre_sum]
            pre_sum.append(node.val)
            for x in pre_sum:
                if x == target:
                    cnt += 1
            dfs(node.left, clist, pre_sum)
            dfs(node.right, clist, pre_sum)
            clist.pop()
            pre_sum.pop()
            pre_sum = [x - node.val for x in pre_sum]

        dfs(root, [], [])
        return cnt


if __name__ == '__main__':
    so = Solution()
    so.pathSum()