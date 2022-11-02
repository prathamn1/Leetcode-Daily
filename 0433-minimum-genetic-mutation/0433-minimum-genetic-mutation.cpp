class Solution {
public:
    bool is_convertible(string a,string b,int n) {
        int ct=0;
        for(int i=0;i<8;i++) {
            if(a[i]!=b[i]) {
                ct++;
            }
        }
        if(ct==1) {
            
            return true;
        }
        return false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        int n=bank.size(),curr_level=0;
        vector<bool>is_visited(n,false);
        q.push(start);
        while(not q.empty()) {
            int st=q.size();
            for(int i=0;i<st;i++) {
                string temp=q.front();
                q.pop();
                // cout<<temp<<endl;
                if(temp==end) {
                    return curr_level;
                }
                for(int j=0;j<n;j++) {
                    if(not is_visited[j] and is_convertible(temp,bank[j],n)) {
                        q.push(bank[j]);
                        is_visited[j]=true;
                    }
                }
            }
            curr_level++;
        }
        return -1;
    }
};