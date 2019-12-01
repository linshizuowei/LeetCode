#! -*- encoding: utf-8 -*- 

'''
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

'''
思路：
字串问题，首先考虑two points思路，本题two points常规思路复杂度是O（n2 ），即可ac
start指针首先固定，end指针每次移动一个位置，判断该位置是否重复，若重复，记录字串长度，并start指针开始移动，
每次一步，直到找到和end指针重复的字符串，从重复字符串下一位置重新开始上述循环
还需考虑最后一个字串，因为正常退出循环后最后一个字串的长度还未记录
'''

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 0
        start = 0
        end = 0
        seen = set()
        
        while end < len(s):
            if s[end] in seen:
                leng = len(s[start:end])
                while start < end:
                    if s[start] == s[end]:
                        start += 1
                        break
                    seen.remove(s[start])
                    start += 1
                ret = max(ret, leng)
            seen.add(s[end])
            end += 1
        return max(ret, len(s[start:end]))
