class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        d = dict()
        start = 0
        max_count = 0
        for end in range(len(fruits)):
            fruit = fruits[end]
            d[fruit] = d.get(fruit, 0) + 1

            while(len(d)>2):
                d[fruits[start]] -= 1
                if(d[fruits[start]] == 0):
                    d.pop(fruits[start])
                start += 1
            
            max_count = max(max_count, end-start+1)
        
        return max_count
