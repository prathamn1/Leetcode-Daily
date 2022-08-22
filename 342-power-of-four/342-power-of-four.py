class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        b=bin(n)[2:]
        if n<0:
            return False
        if b.count('1')==1 and (len(b)-1)%2==0:
            return True
        return False