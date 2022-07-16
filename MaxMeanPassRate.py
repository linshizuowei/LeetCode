import heapq


class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        """
        :type classes: List[List[int]]
        :type extraStudents: int
        :rtype: float
        """
        heap = []
        for it in classes:
            heap.append([-1 * ((it[0] + 1) * 1.0 / (it[1] + 1) - it[0] / it[1]), it[0], it[1]])
        heapq.heapify(heap)
        for i in range(extraStudents):
            top = heapq.heappop(heap)
            newit = -1 * ((top[1] + 2) * 1.0 / (top[2] + 2) - (top[1] + 1) / (top[2] + 1))
            heapq.heappush(heap, [newit, top[1] + 1, top[2] + 1])
        print(heap)
        sums = 0
        for it in heap:
            sums += it[1]*1.0 / it[2]
        return sums / len(classes)

if __name__ == '__main__':
    calsses = [[1, 2], [3, 5], [2, 2]]
    calsses = [[2,4],[3,9],[4,5],[2,10]]
    es = 4
    so = Solution()
    print(so.maxAverageRatio(calsses, es))