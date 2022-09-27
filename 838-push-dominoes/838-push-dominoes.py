class Solution:
    def pushDominoes(self, domino: str) -> str:
        n=len(domino)
        ans=[x for x in domino]
        i=0
        while i<n and domino[i]=='.':
            i+=1
        start=i
        if start>=0 and start<n and domino[start]=='L':
            for j in range(i):
                ans[j]=domino[start]
        i=n-1
        while i>=0 and domino[i]=='.':
            i-=1
        stop=i
        if stop >=0 and stop <n and domino[stop]=='R':
            for j in range(i+1,n):
                ans[j]=domino[stop]
        while start<stop:
            right=start+1
            while right<=stop and domino[right]=='.':
                right+=1
            l=start+1
            r=right-1
            if domino[start]=='L' and domino[right]=='R':
                start=right
            elif domino[start]==domino[right]:
                k=''
                if domino[start]=='L':
                    k=domino[right]
                else:
                    k=domino[start]
                for j in range(l,right):
                    ans[j]=k
                start=right
            else:
                while l<=r:
                    if l==r:
                        ans[l]='.'
                    else:
                        ans[l]=domino[start]
                        ans[r]=domino[right]
                    l+=1
                    r-=1
                start=right
        return ''.join(ans)
                    
# print(Solution().pushDominoes(".L.R...LR..L.."))