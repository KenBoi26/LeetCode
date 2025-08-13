class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def mapped_value(num):
            return int(''.join(str(mapping[int(d)]) for d in str(num)))
        
        return sorted(nums, key=mapped_value)