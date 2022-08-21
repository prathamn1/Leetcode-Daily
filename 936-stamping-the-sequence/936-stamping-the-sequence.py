class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        ans=[]
        permute_stamp=set()
        for i in range(len(stamp)):
            for j in range(len(stamp)-i):
                permute_stamp.add('#'*i+stamp[i:len(stamp)-j]+'#'*j)
        """intuition for generating permutations -: abc ab# a## ; #bc #b# ; ##c ie. i number of # from the beginning and j number of # from the end and remaining, letter of stamp"""
        # print(permute_stamp)
        final_target='#'*len(target)
        while target!=final_target:  # till our target is converted into all '#'
            found=False
            for i in range(len(target)-len(stamp)+1,-1,-1):
                if target[i:i+len(stamp)] in permute_stamp:  #if some part of target is in our permutations
                    target=target[:i]+'#'*len(stamp)+target[i+len(stamp):] # changing the found part of target to '#'
                    ans.append(i) # appending the starting changed index to ans
                    found=True
                """# when we could not find any part of our target to be replaced by our permutations of stamp, implying that we could not change our target to '#' thus return False or empty list []"""
            if not found:  
                return []
        return reversed(ans)
            
        
        
        
        
        
        
        
        
        """
        class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        slen, tlen = len(stamp), len(target)
        res = []
        
        s_covers = set()   # create permutation of cover on characters in stamp
        for i in range(slen):
            for j in range(slen - i):
                s_covers.add('#' * i + stamp[i:slen-j] + '#' * j)
		# print(s_covers)
		
        done = '#' * tlen
		
        p = tlen - slen 
        while target != done:
            
            found = False
            for i in range(p, -1, -1):
                if target[i: i+slen] in s_covers:
                    target = target[:i] + '#' * slen + target[i+slen:]  # add the mask to the target
                    res.append(i)
                    found = True
            if not found:   # if we cannot find where to put the stamp, return empty array
                return []
        
        return res[::-1]
        """