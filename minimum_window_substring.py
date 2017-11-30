# -*- encoding: utf-8 -*-
"""
76题
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S
"""
"""
思路就是用两个指针标识子串的左右边界，右边界将新字符加入子串，直到包含t中的全部字符，然后左边界剔除字符以缩小子串，
直到将任意一个t中的字符剔除后，此时，s[左边界-1:右边界]这个子串是包含有t中全部字符的，是一个备选子串。
循环此过程直到s字符串结束，返回最短的备选子串。

注1：t中的重复字符要全部包含，如 t --> ['aa'], s --> ['adbaca'], 最短子串是'aca',两个a都要包括在内。
注2：对于子串问题来说，双指针是很常用的方法，因为子串是原字符串中的一段连续字符（子序列可以是不连续的），双指针刚
     好可以将子串的头尾锁定，而指针移动的停驻点通常是满足条件的子串中最后一个字符在原字符串中的位置。
"""

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        tmp = {}; src = {}
        for c in t:
            src.setdefault(c, 0)
            src[c] += 1
            tmp[c] = 0
        ll = 0; rr = 0
        mini = None
        sig = 0
        while True:
            if rr >= len(s):
                break
            if s[rr] in tmp:
                tmp[s[rr]] += 1
                if tmp[s[rr]] <= src[s[rr]]:
                    sig += 1
            if sig == len(t):
                while True:
                    if s[ll] in tmp: tmp[s[ll]] -= 1
                    if s[ll] in tmp and tmp[s[ll]] < src[s[ll]]:
                        if not mini or len(s[ll:rr+1]) < len(mini):
                            mini = s[ll:rr+1]
                        ll += 1
                        sig -= 1
                        break
                    ll += 1
            rr += 1
        return mini if mini else ""

so = Solution()
print so.minWindow("ADOBECODEBANC", "ABC")