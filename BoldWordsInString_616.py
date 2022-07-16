class Solution:
    def addBoldTag(self, s, words) -> str:
        lens = len(s)
        if lens == 0:
            return s

        ###   Noted !!!!!!! ***************************
        mask = [False for _ in range(lens)]
        for i in range(lens):
            for w in words:
                lenw = len(w)
                if i + lenw <= lens and s[i:i + lenw] == w:
                    for j in range(i, i + lenw):
                        mask[j] = True

        res = []
        for i in range(lens):
            if mask[i] == True and (i==0 or mask[i-1] == False):
                res.append('<b>')
            res.append(s[i])
            if mask[i] == True and (i==lens-1 or mask[i+1]==False):
                res.append('</b>')


'''class Solution:
    def addBoldTag(self, s: str, dict: List[str]) -> str:
        n = len(s)
        if n == 0:
            return ""

        mask = [False for _ in range(n)]    #对每个位置进行标记。匹配成功就True，未匹配上就False

        for i in range(n):      #遍历每一个位置，作为开头
            for word in dict:   #遍历每一个单词
                word_len = len(word)
                if i + word_len <= n and s[i: i + word_len] == word:    #未超界，且匹配成功
                    for j in range(i, i + word_len):    #把匹配上的所谓位置，全都置True
                        mask[j] = True

        res = []
        for i in range(n):
            if mask[i]==True and (i==0 or mask[i-1]==False):    #开头
                res.append("<b>")

            res.append(s[i])

            if mask[i]==True and (i==n-1 or mask[i+1]==False):  #结尾
                res.append("</b>")

        return "".join(res)

作者：Hanxin_Hanxin
链接：https://leetcode-cn.com/problems/add-bold-tag-in-string/solution/c-python3-bao-li-mo-ni-huan-yao-xiang-da-9w8s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''