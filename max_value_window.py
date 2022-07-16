import heapq
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        heap = []
        ret = []
        idx = 0
        leng = len(nums)
        while idx < leng and idx < k:
            heap.append([nums[idx]*-1, idx])
            idx += 1
        heapq.heapify(heap)
        topn, topi = heapq.heappop(heap)
        ret.append(topn*-1)
        heapq.heappush(heap, [topn, topi])
        left = 1
        # right = k
        for i in range(k, leng):
            while heap:
                topn, topi = heapq.heappop(heap)
                if topi >= left:
                    heapq.heappush(heap, [topn, topi])
                    break
            heapq.heappush(heap, [nums[i]*-1, i])
            topn, topi = heapq.heappop(heap)
            ret.append(topn*-1)
            left += 1
        return ret

if __name__ == '__main__':
    so = Solution()
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    print(so.maxSlidingWindow(nums, k))