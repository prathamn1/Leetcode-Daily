class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n=len(arr)
        temp=[]
        for i in range(n-1):
            if arr[i]<arr[i+1]:
                temp.append(0)
            elif arr[i]>arr[i+1]:
                temp.append(1)
            else:
                temp.append(-10)
        ans=1
        c=1
        if len(temp)==1:
            if temp[0]!=-10:
                return 2
            else:
                return 1
        for i in range(1,len(temp)):
            if temp[i]==1-temp[i-1]:
                c+=1
            else:
                if temp[i]==-10:
                    c=0
                else:
                    c=1
            ans=max(c+1,ans)
        return ans