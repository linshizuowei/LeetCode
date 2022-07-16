# -*- encoding: utf-8 -*-

"""
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def sort(s1, s2):
            s = s1 if len(s1) < len(s2) else s2
            leng = len(s)
            for i in range(leng):
                if s1[i] < s2[i]:
                    return s1
                elif s1[i] > s2[i]:
                    return s2
            return s
        dic = {}
        for it in tickets:
            From, To = it
            if From not in dic:
                dic[From] = []
            dic[From].append(To)
        if not tickets or 'JFK' not in dic:
            return []
        for k, v in dic.items():
            v.sort()
        cur_f = 'JFK'
        plist = [cur_f]
        #import pdb;pdb.set_trace()
        while True:
            if cur_f not in dic or not dic[cur_f]:
                return plist
            c = dic[cur_f].pop(0)
            plist.append(c)
            cur_f = c

so = Solution()
inputs = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
ret = so.findItinerary(inputs)
print(ret)
