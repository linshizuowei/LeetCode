# -*- encoding: utf-8 -*-
"""
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
"""
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        """
        每一行尽可能多的放单词，剩下的空间用空格填充，空格尽可能均匀放置，无法均匀的情况左边优先放，
        但是，一行只有一个单词的情况下，空格都放右边。
        """
        tmp_word = []
        wid = maxWidth
        res = []
        for i in range(len(words)):
            tmp_word.append(words[i])
            tmp_word.append(' ')
            wid = wid - len(words[i]) - 1
            if i+1 < len(words) and len(words[i+1]) > wid:
                tmp_word.pop()
                wid += 1
                evesp = wid / (len(tmp_word)/2) if len(tmp_word)/2 != 0 else wid
                re = wid % (len(tmp_word)/2) if len(tmp_word)/2 != 0 else 0
                for j in range(1, len(tmp_word), 2):
                    tmp_word[j] += ' '*evesp
                    if re > 0:
                        tmp_word[j] += ' '
                        re -= 1
                if len(tmp_word) == 1:
                    tmp_word.append(' ' * evesp )
                res.append(''.join(tmp_word))
                tmp_word = []
                wid = maxWidth
        if tmp_word:
            tmp_word.pop()
            s = ''.join(tmp_word)
            res.append(s + ' '*(maxWidth-len(s)))
        return res

so = Solution()
print so.fullJustify(["Listen","to","many,","speak","to","a","few."], 6)