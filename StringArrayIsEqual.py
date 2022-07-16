class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        idx1 = 0
        idx2 = 0
        while word1 or word2:
            if idx1 == 0:
                s1 = word1.pop(0)
            if idx2 == 0:
                s2 = word2.pop(0)
            while idx1 < len(s1) and idx2 < len(s2):
                if s1[idx1] != s2[idx2]:
                    return False
                idx1 += 1
                idx2 += 1
            if idx1 >= len(s1):
                idx1 = 0
            if idx2 >= len(s2):
                idx2 = 0
        if word1 or word2:
            return False
        return True


if __name__ == '__main__':
    w1 = ["abc","d","defg"]
    w2 = ["abcddef"]
    so = Solution()
    so.arrayStringsAreEqual(w1, w2)