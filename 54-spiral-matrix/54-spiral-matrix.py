class Solution:
    def spiralOrder(self, a):
        n=len(a[0])
        m=len(a)
        left=0
        right=n-1
        top=0
        bottom=m-1
        ans=[]
        while left<=right and top<=bottom:
            for i in range(left,right+1):
                ans.append(a[top][i])
            top+=1
            for i in range(top,bottom+1):
                ans.append(a[i][right])
            right-=1
            if left>right or top >bottom:
                break
            for i in range(right,left-1,-1):
                ans.append(a[bottom][i])
            bottom-=1
            for i in range(bottom,top-1,-1):
                ans.append(a[i][left])
            left+=1
        return ans