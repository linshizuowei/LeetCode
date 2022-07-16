class Solution:
    def hasPath(self, maze, start, destination) -> bool:
        if len(maze) == 0:
            return False

        stack = [(start[0], start[1], 0, 1)]
        row = len(maze)
        col = len(maze[0])
        visited = [[0] * col for _ in range(row)]
        visited[start[0]][start[1]] = -1
        while stack:
            currow, curcol, stepr, stepc = stack.pop()
            if currow == destination[0] and curcol == destination[1]:
                return True
            for r, c in [[0, -1], [-1, 0], [0, 1], [1, 0]]:
                tr = currow
                tc = curcol
                while 0 <= tr + r < row and 0 <= tc + c < col \
                        and maze[tr + r][tc + c] == 0:
                    tr += r
                    tc += c
                if visited[tr][tc] == -1:
                    continue
                visited[tr][tc] = -1
                stack.append((tr, tc, r, c))
        return False


if __name__ == '__main__':
    so = Solution()
    ret = so.hasPath([[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]],
                [0,4],
                [4,4])
    print(ret)