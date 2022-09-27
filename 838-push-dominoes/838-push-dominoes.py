class Solution:
    def pushDominoes(self, domino: str) -> str:
        domino='L'+domino+'R'  # adding boundaries to make code small
        n=len(domino)
        ans=[x for x in domino]
        start=0
        stop=n-1
        while start<stop:
            right=start+1
            while right<=stop and domino[right]=='.':
                right+=1
            l=start+1
            r=right-1
            if domino[start]==domino[right]:
                for j in range(l,right):
                    ans[j]=domino[start]
            elif domino[start]=='R' and domino[right]=='L':
                while l<=r:
                    if l==r:
                        ans[l]='.'
                    else:
                        ans[l]=domino[start]
                        ans[r]=domino[right]
                    l+=1
                    r-=1
            start=right
        return ''.join(ans[1:n-1])


        