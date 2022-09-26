class Solution {
public:
    void get_ready(vector<int>&parent,vector<int>&rank) {
        for(int i=0;i<26;i++) {
            parent.push_back(i);
            rank.push_back(1);     
        }
    }
    int dsu_find(int a,vector<int>&parent) {
        if(parent[a]==a) {
            return a;
        }
        return parent[a]=dsu_find(parent[a],parent);
    }
    void dsu_union(int a ,int b,vector<int>&parent,vector<int>&rank) {
        a=dsu_find(a,parent);
        b=dsu_find(b,parent);
        if(a!=b) {
            if(rank[a]<rank[b]) {
                swap(a,b);
            }
            parent[b]=a;
            rank[a]+=rank[b];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent,rank;
        vector<pair<int,int>>not_equal_to;
        get_ready(parent,rank);
        for(auto i:equations) {
            if(i[1]=='!') {
                not_equal_to.push_back(make_pair(i[0]-97,i[3]-97));
            }else {
                dsu_union(i[0]-97,i[3]-97,parent,rank);
            }
        }
        for(auto i:not_equal_to) {
            if(dsu_find(i.first,parent)==dsu_find(i.second,parent)) {
                return false;
            }
        }
        return true;
    }
};