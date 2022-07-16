class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp_array = [[False] * (len(s) + 1) for _ in range(len(p) + 1)]
        dp_array[0][0] = True
        for i in range(1, len(p) + 1):
            if p[i - 1] == '*':
                dp_array[i][0] = True
            else:
                break

        for pi in range(1, len(p) + 1):
            for si in range(1, len(s) + 1):
                if p[pi - 1] == '*':
                    dp_array[pi][si] = dp_array[pi - 1][si] or dp_array[pi][si - 1]
                elif p[pi-1] == '?' or p[pi-1] == s[si-1]:
                    dp_array[pi][si] = dp_array[pi - 1][si - 1]
        return dp_array[-1][-1]

if __name__ == '__main__':
    so = Solution()
    so.isMatch("acdcb", "a*c?b")