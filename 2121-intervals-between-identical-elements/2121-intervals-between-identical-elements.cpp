// when solved on a copy make some graphic lines while calculating the time for a particular element .
// use intervals between adjacent indexes instead of indexes itself and soon you will arrive at a formula.
class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans(n);
        unordered_map<int,vector<int>>position;
        for(int i=0;i<n;i++) {
            position[nums[i]].emplace_back(i);
        }
        for(auto [ele,pos]:position) {
            int leng=pos.size();
            if(leng==1) {
                ans[pos[0]]=0;
            }else {
                long long int s1=0,s2=0;
                for(int i=1;i<leng;i++) {
                    s1+=(leng-i)*(pos[i]-pos[i-1]);
                }
                for(int i=0;i<leng;i++) {
                    if(i==0) {
                        ans[pos[i]]=s1;
                    }else {
                        s1-=(leng-i)*(pos[i]-pos[i-1]);
                        s2+=i*(pos[i]-pos[i-1]);
                        ans[pos[i]]=s1+s2;
                    }   
                }
            }
        }
        return ans;
    }
};