"""
897. 递增顺序搜索树
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

示例 1：
输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

示例 2：
输入：root = [5,1,7]
输出：[1,null,5,null,7]
 

提示：
树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:

        # recursive way
        def search(node, cnode):
            if not node:
                return cnode

            cnode = search(node.left, cnode)
            tnode = TreeNode(node.val)
            cnode.right = tnode
            cnode = tnode
            cnode = search(node.right, cnode)
            return cnode

        nroot = TreeNode(-1)
        search(root, nroot)
        return nroot.right

        # nonrecursive way
        stack = []
        nroot = TreeNode(-1)
        cnode = nroot
        node = root
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                tnode = TreeNode(node.val)
                cnode.right = tnode
                cnode = tnode
                node = node.right
        return nroot.right
