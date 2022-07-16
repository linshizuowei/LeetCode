class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        dp_array = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        for i in range(1, len(s2) + 1):
            dp_array[0][i] = dp_array[0][i - 1] + ord(s2[i - 1])
        for i in range(1, len(s1) + 1):
            dp_array[i][0] = dp_array[i - 1][0] + ord(s1[i - 1])

        for row in range(1, len(s1) + 1):
            for col in range(1, len(s2) + 1):
                if s1[row - 1] == s2[col - 1]:
                    dp_array[row][col] = dp_array[row - 1][col - 1]
                else:
                    dp_array[row][col] = min(dp_array[row - 1][col] + ord(s1[row - 1]),
                                             dp_array[row][col - 1] + ord(s2[col - 1]))
        return dp_array[-1][-1]

if __name__ == '__main__':
    so = Solution()
    so.minimumDeleteSum("delete", "leet")