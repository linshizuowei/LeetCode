"""
291. 单词规律 II
给你一种规律 pattern 和一个字符串 s，请你判断 s 是否和 pattern 的规律相匹配。

如果存在单个字符到字符串的 双射映射 ，那么字符串 s 匹配 pattern ，即：如果pattern 中的每个字符都被它映射到的字符串替换，那么最终的字符串则为 s 。双射 意味着映射双方一一对应，不会存在两个字符映射到同一个字符串，也不会存在一个字符分别映射到两个不同的字符串。

 

示例 1：

输入：pattern = "abab", s = "redblueredblue"
输出：true
解释：一种可能的映射如下：
'a' -> "red"
'b' -> "blue"
示例 2：

输入：pattern = "aaaa", s = "asdasdasdasd"
输出：true
解释：一种可能的映射如下：
'a' -> "asd"
示例 3：

输入：pattern = "aabb", s = "xyzabcxzyabc"
输出：false
 

提示：

1 <= pattern.length, s.length <= 20
pattern 和 s 由小写英文字母组成
"""


class Solution:
    def wordPatternMatch(self, pattern, s):
        def backtrack(pidx, sidx):
            nonlocal psmap
            nonlocal spmap
            if pidx >= plen:
                if sidx >= slen:
                    return True
                else:
                    return False

            p = pattern[pidx]
            if p in psmap:
                sval = psmap[p]
                if sval == s[sidx: sidx+len(sval)]:
                    res = backtrack(pidx+1, sidx+len(sval))
                    if res:
                        return res
                else:
                    return False
            else:
                for i in range(sidx, slen):
                    schr = s[sidx:i+1]
                    if schr not in spmap:
                        psmap[p] = schr
                        spmap[schr] = p
                        res = backtrack(pidx+1, i+1)
                        psmap.pop(p)
                        spmap.pop(schr)
                        if res:
                            return res
            return False

        plen = len(pattern)
        slen = len(s)
        if plen > slen:
            return False
        psmap = {}
        spmap = {}
        return backtrack(0, 0)


if __name__ == '__main__':
    so = Solution()
    pa = 'abab'
    s = 'cccc'
    print(so.wordPatternMatch(pa, s))
