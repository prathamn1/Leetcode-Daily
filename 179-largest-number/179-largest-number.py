"""class comparator(str):
    def __lt__(x,y):
        return x+y>y+x
    
class Solution:
	def largestNumber(self,arr):
	    ans=''.join(sorted(map(str,arr),key=comparator))
	# to check if the final string contains only zeroes then return just single zero
	    return '0' if ans[0]=='0' else ans"""
from functools import cmp_to_key
class Solution:
    def largestNumber(self,arr):
        def comparator(x,y):
            if x+y>y+x:
                return -1
            elif x==y:
                return 0
            else:
                return 1
        ans=''.join(sorted(map(str,arr),key=cmp_to_key(comparator)))
        return '0' if ans[0]=='0' else ans
