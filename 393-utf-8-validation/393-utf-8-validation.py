class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        n=len(data)
        i=0
        while i<n:
            # data[i]=bin(data[i])[2:].rjust(8,'0')
            ct=bin(data[i])[2:].rjust(8,'0').find('0')-1
            if ct==-2 or ct>3:
                return False
            elif ct==0:
                if bin(data[i])[2:].rjust(8,'0')[0]!='0':
                    return False
                i+=1
            else:
                i+=1
                for j in range(i,i+ct):
                    if j>=n or bin(data[j])[2:].rjust(8,'0')[:2]!='10':
                        return False
                    ct-=1
                    i+=1    
        return True
                
                
                