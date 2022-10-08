class Solution:
    def threeSumClosest(self, a: List[int], target: int) -> int:
        i=0
        a.sort()
        small=-10**7
        big=10**7
        while i<len(a)-1:
            while len(a)>i>0 and a[i]==a[i-1]:
                i+=1
            j=i+1
            k=len(a)-1
            while j<k:
                add=a[i]+a[j]+a[k]
                if add <target:
                    small=max(small,add)
                    j+=1
                elif add>target:
                    big=min(big,add)
                    k-=1
                else:
                    return target

            i+=1
        if abs(small-target) <abs(big-target):
            return small
        else:
            return big