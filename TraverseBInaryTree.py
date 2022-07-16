# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def search_tree(node):

    # pre-order
    if node is None:
        return
    print(node.val)
    search_tree(node.left)
    search_tree(node.right)

    # middle-order
    if node is None:
        return
    search_tree(node.left)
    print(node.val)
    search_tree(node.right)

    # post-order
    if node is None:
        return
    search_tree(node.left)
    search_tree(node.right)
    print(node.val)

    # pre-order without recurrent
    stack = []
    while stack or node:
        if node:
            print(node.val)
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            node = node.right

    # mid-order without recurrent
    stack = []
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            print(node.val)
            node = node.right

    # post-order without recurrent
    stack = []
    ret = []
    while stack or node:
        if node:
            ret.append(node.val)
            stack.append(node)
            node = node.right
        else:
            node = stack.pop()
            node = node.left
    print(ret[::-1])
