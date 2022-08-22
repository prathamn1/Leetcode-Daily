class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return ((n>0) and not (n&(n-1)) and not (n-1)%3)
        # b=bin(n)[2:]
        # if n<0:
        #     return False
        # if b.count('1')==1 and (len(b)-1)%2==0:
        #     return True
        # return False
        """return num > 0 and num & (num-1) == 0 and 0b1010101010101010101010101010101 & num == num """ 
    
    # to check a number is a power of two ( n>0 and n&(n-1)==0)
    # for power of 4 the only one present must be present at odd position so to check that we & with big number according to constraints
    """
16=                           10000
    1010101010101010101010101010101
    _______________________________
    0000000000000000000000000010000  equal to num
    """
    
    #also a number will be a power of 4 if it is a power of two and n-1 is also divisible by three
        