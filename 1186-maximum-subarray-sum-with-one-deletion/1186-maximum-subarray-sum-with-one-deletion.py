#do kadane algo forward and back ward and store sum at every step now to discard one element( i+1 index) and take the continuos sum further we can take use of our backward kadane sum of i+2 index


class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        forward_sum=[0]*len(arr)
        backward_sum=[0]*len(arr)
        summation_forward=0
        summation_backward=0
        for i in range(len(arr)):
            summation_forward+=arr[i]
            summation_backward+=arr[len(arr)-i-1]
            forward_sum[i]=summation_forward
            backward_sum[len(arr)-i-1]=summation_backward
            if summation_forward<0:
                summation_forward=0
            if summation_backward<0:
                summation_backward=0
            
        ans=float('-inf')
        for i in range(len(arr)):
            if i+2<len(arr):
                ans=max(ans,forward_sum[i],forward_sum[i]+backward_sum[i+2])
            else:
                ans=max(ans,forward_sum[i])
        return ans
            
        
