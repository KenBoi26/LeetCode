class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        used = [0] * len(baskets)
        unplaced = 0

        for i in fruits:
            flag = True
            for k in range(len(baskets)):
                j = baskets[k]
                print(i, j)
                if used[k] == 0 and j >= i:
                    used[k] = 1
                    flag = False
                    break
            print(used)
            if flag:
                unplaced += 1

        return unplaced
