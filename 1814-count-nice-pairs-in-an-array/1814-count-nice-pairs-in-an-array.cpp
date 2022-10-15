class Solution {
public:
    int reverse_num(long num) {
        long n=num,place_value=1,rev=0,ct=1;
        while(n>0) {
            n/=10;
            place_value*=10;
        }
        place_value/=10;
        while(num>0) {
            int start_digit=num/place_value;
            rev+=start_digit*ct;
            ct*=10;
            num%=place_value;
            place_value/=10;   
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long ans=0;
        for(int i=0;i<nums.size();i++) {
            int reverse=reverse_num(nums[i]);
            cout<<reverse<<" ";
            ans=(ans+mp[nums[i]-reverse])%1000000007;
            mp[nums[i]-reverse]++;
        }
        return ans;
    }
};