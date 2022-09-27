class Solution:
    def maxProduct(self, a: List[int]) -> int:
        # the idea is to keep track of minimum and maximum product every time we multiply the new number
        maximum_product=minimum_product=ans=a[0]
        i=1
        while i<len(a):
            product_1=maximum_product*a[i]
            product_2=minimum_product*a[i]
            maximum_product=max(product_1,product_2,a[i]) # for [-1,2] the max product will be element 2 itself
            minimum_product=min(product_1,product_2,a[i]) # for [-1,-8] the min product will be element 8 itself
            ans=max(ans,maximum_product)
            i+=1
        return ans