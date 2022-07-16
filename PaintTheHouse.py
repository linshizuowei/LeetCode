class Solution:
    def minCost(self, costs) -> int:
        if len(costs) == 0:
            return 0
        elif len(costs) == 1:
            return min(costs[0])

        tmpCost = [0]*3
        totalCost = costs[0]
        for row in range(1, len(costs)):
            for col in range(3):
                if col == 0:
                    tmpCost[col] = costs[row][col] + min(totalCost[1], totalCost[2])
                elif col == 1:
                    tmpCost[col] = costs[row][col] + min(totalCost[0], totalCost[2])
                elif col == 2:
                    tmpCost[col] = costs[row][col] + min(totalCost[0], totalCost[1])
            totalCost = tmpCost[:]
        return min(totalCost)


if __name__ == '__main__':
    so = Solution()
    costs = [[17,2,17],[16,16,5],[14,3,19]]
    ret = so.minCost(costs)
    print(ret)