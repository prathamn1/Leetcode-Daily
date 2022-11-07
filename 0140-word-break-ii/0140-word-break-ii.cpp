class Node {
  public:
    Node * links[26];
    bool flag=false;
    bool is_contains_key(char key) {
        return links[key-'a']!=NULL;
    }
    void put_key(char ch,Node * newNode) {
        links[ch-'a']=newNode;
    }
    Node * get_next_node(char ch) {
        return links[ch-'a'];
    }
    void set_end() {
        flag=true;
    }
    bool is_end() {
        return flag;
    }
};

class Solution {
public:
Node * root;
    Solution() {
        root = new Node();
    }
    void insert(string word) {
        Node * curr_node=root;
        for(int i=0;i<word.size();i++) {
            if(not curr_node->is_contains_key(word[i])) {
                curr_node->put_key(word[i],new Node());
            }
            curr_node=curr_node->get_next_node(word[i]);
        }
        curr_node->set_end();
    }
    void solve(int curr_index,string curr_string,Node* curr_node,string& s,vector<string>&ans) {
        if(curr_index==s.size()) {
            curr_string.pop_back();
            ans.push_back(curr_string);
        }
        for(int i=curr_index;i<s.size();i++) {
            if(curr_node->is_contains_key(s[i])) {
                curr_string+=s[i];
            }else {
                return;
            }
            curr_node=curr_node->get_next_node(s[i]);
            if(curr_node->is_end()) {
                solve(i+1,curr_string+" ",root,s,ans);
            }
        }    
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) {
            insert(i);
        }
        vector<string>ans;
        solve(0,"",root,s,ans);
        return ans;
    }
};