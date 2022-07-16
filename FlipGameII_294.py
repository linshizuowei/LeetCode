class Solution:
    def canWin(self, currentState: str) -> bool:
        s = list(currentState)
        n = len(s)
        for i in range(n - 1):
            if s[i] == '+' and  s[i+1] == '+':
                s[i] = '-'
                s[i+1] = '-'
                if self.canWin( ''.join(s) ) == False:
                    return True
                s[i] = '+'              #回溯，有借有还
                s[i+1] = '+'            #回溯，有借有还
        return False

if __name__ == '__main__':
    so = Solution()
    ret = so.canWin("++++")
    print(ret)