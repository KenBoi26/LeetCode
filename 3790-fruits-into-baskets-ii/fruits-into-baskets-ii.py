class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unplaced = 0

        for i in fruits:
            for k in range(len(baskets)):
                if baskets[k] >= i:
                    baskets[k] = 0
                    break
            else:
                unplaced += 1

        return unplaced
