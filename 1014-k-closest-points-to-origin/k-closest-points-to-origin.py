class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        result = []
        heap = []

        for i in range(len(points)):
            distance = points[i][0] * points[i][0] + points[i][1] * points[i][1]

            heapq.heappush(heap, (-distance, points[i]))

            if len(heap) > k:
                heapq.heappop(heap)

        while heap:
            result.append(heapq.heappop(heap)[1])

        return result