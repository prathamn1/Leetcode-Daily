class Solution {
public:
    bool check_disjoint(vector<int>&v1 , vector<int>&v2) {
        for(auto i:v1) {
            if(find(v2.begin(),v2.end(),i)!=v2.end()) {
                return false;
            }
        }
        return true;
    }
    bool check_palindrome(vector<int>&v,string &s) {
        int l=0,r=v.size()-1;
        while(l<r) {
            if(s[v[l]]!=s[v[r]]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void generate_subsequences(int curr_index,string &s,vector<int>&curr_sub,vector<vector<int>>&subs) {
        if(curr_index==s.size()) {
            if(check_palindrome(curr_sub,s)) {
                subs.push_back(curr_sub);
            } 
            return;
        }
        generate_subsequences(curr_index+1,s,curr_sub,subs);
        curr_sub.push_back(curr_index);
        generate_subsequences(curr_index+1,s,curr_sub,subs);
        curr_sub.pop_back();
    }
    void print(vector<int>&v) {
        cout<<"{ ";
        for(auto i:v) {
            cout<<i<<" ";
        }
        cout<<" }";
    }
    int maxProduct(string s) {
        int n=s.size();
        vector<int>curr_sub;
        vector<vector<int>>subs;
        generate_subsequences(0,s,curr_sub,subs);
        int ans=0;
        int k=subs.size();
        for(int i=0;i<k;i++) {
            for(int j=i+1;j<k;j++) {
                if(check_disjoint(subs[i],subs[j])) {
                    int l=subs[i].size();
                    int m=subs[j].size();
                    ans=max(ans,l*m);
                }
            }
        }
        return ans;
    }
};