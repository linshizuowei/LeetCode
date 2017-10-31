# -*- coding:utf-8 -*-

"""
有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
测试样例：
1
返回：1
"""

class GoUpstairs:
    def countWays(self, n):
        def count(res, n):
            if n >= 1:
                res = count(res, n-1)
            if n >= 2:
                res = count(res, n-2)
            if n >= 3:
                res = count(res, n-3)
            if n == 0:
                res += 1
            return res

        return count(0, n)

if __name__ == '__main__':
    up = GoUpstairs()
    print up.countWays(25)