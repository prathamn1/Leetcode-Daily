class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels=['a','e','i','o','u','A','E','I','O','U']
        first_half=second_half=0
        for i,j in zip(range(len(s)//2),range(len(s)//2,len(s))):
            if s[i] in vowels:
                first_half+=1
            if s[j] in vowels:
                second_half+=1
        return first_half==second_half