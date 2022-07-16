class Solution:
    def shortestDistance(self, grid) -> int:
        if len(grid) == 0:
            return -1
        Row = len(grid)
        Col = len(grid[0])
        count = [[0]*Col for _ in range(Row)]
        buildings = []
        for r in range(Row):
            for c in range(Col):
                if grid[r][c] == 1:
                    count[r][c] = -1
                    buildings.append((r,c))
                elif grid[r][c] == 2:
                    count[r][c] = -2
        for br, bc in buildings:
            queue = [(br, bc, 0)]
            visited = set()
            visited.add((br, bc))
            while queue:
                currow, curcol, dis = queue.pop(0)
                if grid[currow][curcol] == 0:
                    count[currow][curcol] += dis
                elif grid[currow][curcol] == 2:
                    continue
                for r, c in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
                    r += currow
                    c += curcol
                    if 0 <= r < Row and 0 <= c < Col and grid[r][c] == 0 and (r, c) not in visited:
                        queue.append((r, c, dis+1))
                        visited.add((r, c))
        maxsum = float('inf')
        for r in range(Row):
            for c in range(Col):
                if count[r][c] > 0:
                    maxsum = min(maxsum, count[r][c])
        maxsum = -1 if maxsum == float('inf') else maxsum
        return maxsum


if __name__ == '__main__':
    so = Solution()
    grid = [[0,2,1],[1,0,2],[0,1,0]]
    ret = so.shortestDistance(grid)
    print(ret)