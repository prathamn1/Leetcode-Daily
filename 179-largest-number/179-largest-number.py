class comparator(str):
    def __lt__(x,y):
        return x+y>y+x
    
class Solution:
	def largestNumber(self,arr):
	    ans=''.join(sorted(map(str,arr),key=comparator))
        # to check if the final string contains only zeroes then return just single zero
	    return '0' if ans[0]=='0' else ans