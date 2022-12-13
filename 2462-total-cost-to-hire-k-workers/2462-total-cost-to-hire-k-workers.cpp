class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        if(a.first==b.first) {
            return a.second>b.second;
        }
        return a.first>b.first;
        
    }
    long long totalCost(vector<int>& costs, int k, int candi) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)>left(cmp),right(cmp);
        int n=costs.size();
        long long int ans=0;
        int l=candi-1,r=n-candi;
        for(int i=0;i<=l;i++) {
            left.push({costs[i],i});
        }
        for(int i=n-1;i>=r;i--){
            right.push({costs[i],i});
        }
        vector<bool>is_visited(n,false);
        while(true) {
            if(k==0 or l==n or r==-1) {
                break;
            }
            pair<int,int>left_mini=left.top();
            pair<int,int>right_mini=right.top();
            pair<int,int>rem_pair;
            
            if(left_mini.first<right_mini.first) {
                rem_pair=left_mini;
            }else if(left_mini.first>right_mini.first) {
                rem_pair=right_mini;
            }else {
                if(left_mini.second<right_mini.second) {
                    rem_pair=left_mini;
                }else {
                    rem_pair=right_mini;
                }
            }
            if(rem_pair==left_mini) {
                l++;
                left.pop();
                while(l<n and is_visited[l]) {
                    l++;
                }
                if(l<n)
                left.push({costs[l],l});
            }
            if(rem_pair==right_mini){
                r--;
                right.pop();
                while(r>=0 and is_visited[r]) {
                    r--;
                }
                if(r>=0) {
                    right.push({costs[r],r});
                }
            }
            ans+=rem_pair.first;
            is_visited[rem_pair.second]=true;
            k--;
        }
        while(k>0) {
            ans+=left.top().first;
            left.pop();
            k--;
        }
        return ans;
    }
};