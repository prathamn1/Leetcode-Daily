class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # first make all the negative values zero because they will interfere with our below algorithm
        # in this algorithm we try to first precompute the array in a way that we go to every element and make it's (absolute value -1)th index element negative 
        # and in the third step we start iterating from 1 to len(nums)+1 , no need for outer range as it's guaranteed that we will find the element till our lenght of the array+1 value
        # to prove the above point let's take the worst example for which we have all the elements from 1-n in our array itself where n is the array size so our answer in this case will be n+1 element
        for i in range(len(nums)):
            if nums[i]<0:
                nums[i]=0
        for i in nums:
            if 0<=abs(i)-1<len(nums):
                if nums[abs(i)-1]>0:
                    nums[abs(i)-1]*=-1
                elif nums[abs(i)-1]==0:
                    nums[abs(i)-1]=-(len(nums)+1) # zero is a neutral element so in this case we make the zero as the negative element so to show that corresponding element to this index is present in our array and to make our algorithm work normally we change zero to a value that will be out of bounds of our array when taken into consideration by the outer for loop
        for i in range(1,len(nums)+1):
            if nums[i-1]>=0:  # checking for >= also as we have also converted our zero to something else negative
                return i
        return len(nums)+1
            