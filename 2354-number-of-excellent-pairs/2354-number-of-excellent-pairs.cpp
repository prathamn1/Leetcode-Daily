// sum of set bits in and + or representation of two numbers is equal to the sum of set bits in these numbers itself . 
// this can be found out as every '1' will contribute to the sum but if for any position i there is '1' in num1 and '1' in num2 then we have already counted one of the one for the or reperesent but the other '1' will have it's role in and of two numbers so we will also count '1' in num 2 for that particular i so we see that every '1' or set bit is contributing to the (no. of set bits in num1 and num2)

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int>diff(nums.begin(),nums.end());
        vector<int>arr;
        for(auto i:diff) {
            arr.push_back(__builtin_popcount(i));
        }
        sort(arr.begin(),arr.end()); // sorting to count the number of pairs -: same as the question for find the number of pairs such that a+b<=k
        long long l=0,r=arr.size()-1,ans=0;
        while(l<=r) {
            if(arr[l]+arr[r]>=k) {
                if(arr[r]*2>=k) {  // to check for the individual pairing of numbers with themselves
                    ans+=1;
                }
                ans+=(r-l)*2;
                r-=1;
            }else {
                if(arr[l]*2>=k) {  //similar to above
                    ans+=1;
                }
                l+=1;
            }
        }
        return ans;
        
    }
};