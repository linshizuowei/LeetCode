# -*- encoding: utf-8 -*-
"""
71. Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
"""

"""
考察栈的使用
"""

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        stack.append(path[0])
        i = 1
        s = ''
        while i < len(path):
            if path[i] != '/':
                s += path[i]
                if i != len(path)-1:
                    i += 1
                    continue
            if s == '..':
                if len(stack) != 1:
                    stack.pop()
                    stack.pop()
            elif s != '' and s != '.':
                stack.append(s)
                stack.append('/')
            s = ''
            i += 1

        if stack[-1] == '/' and len(stack) != 1:
            stack.pop()

        return ''.join(stack)

if __name__ == '__main__':
    s = Solution()
    print s.simplifyPath("/.")
