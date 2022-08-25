from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        count_magazine=Counter(magazine)
        for i in ransomNote:
            if count_magazine.get(i,0)==0:
                return False
            count_magazine[i]-=1
        return True