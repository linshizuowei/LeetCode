class NumMatrix:

    def __init__(self, matrix):
        self.matrix = matrix
        self.row = len(matrix)
        self.col = len(matrix[0])
        self.presum = [[0]*len(matrix[0]) for _ in range(len(matrix))]
        for row in range(len(matrix)):
            self.presum[row][0] = matrix[row][0]
            for col in range(1, len(matrix[0])):
                self.presum[row][col] = matrix[row][col] + self.presum[row][col-1]


    def update(self, row, col, val):
        diff = val - self.matrix[row][col]
        self.matrix[row][col] = val
        for c in range(col, self.col):
            self.presum[row][c] += diff

    def sumRegion(self, row1, col1, row2, col2):
        tsum = 0
        for r in range(row1, row2+1):
            if col1 > 0:
                tsum += self.presum[r][col2] - self.presum[r][col1-1]
            else:
                tsum += self.presum[r][col2]
        return tsum


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
if __name__ == '__main__':
    m = [[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]
    so = NumMatrix(m)
    print(so.sumRegion(2,1,4,3))
    so.update(3, 2, 2)
    print(so.sumRegion(2, 1, 4, 3))