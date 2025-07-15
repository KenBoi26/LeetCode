class Solution:
    def isValid(self, word: str) -> bool:
        if (len(word) >=3) and (word.isalnum()):
            flag1 = False
            flag2 = False
            for i in word:
                if i.lower() in 'aeiou':
                    flag1 = True
                if i.isalpha() and i.lower() not in 'aeiou':
                    flag2 = True
            return flag1 and flag2
        else:
            return False