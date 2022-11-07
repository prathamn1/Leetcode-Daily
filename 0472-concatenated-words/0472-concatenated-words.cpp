class Node {
  public:
    Node * links[26];
    bool flag;

    bool contains_key(char ch) {
        return links[ch-'a']!=NULL;
    }
    bool is_end() {
        return flag;
    }
    void set_end() {
        flag=true;
    }
    void put_key(char ch,Node * node) {
        links[ch-'a']=node;
    }
    Node * get_next_node(char ch) {
        return links[ch-'a'];
    }
};
class Solution {
public:
    Node * root;
    Solution() {
        root=new Node();
    }
    void insert(string& word) {
        Node * curr_node=root;
        for(int i=0;i<word.size();i++) {
            if(not curr_node->contains_key(word[i])) {
                curr_node->put_key(word[i],new Node());
            }
            curr_node=curr_node->get_next_node(word[i]);
        }
        curr_node->set_end();
    }
    
    void solve(int word_index,int curr_index,int concat,Node* curr_node,string& s,vector<bool>&ans) {
        if(ans[word_index] or (curr_index==s.size() and concat>1)) {
            ans[word_index]=true;
            return;
        }
        for(int i=curr_index;i<s.size();i++) {
            if(not curr_node->contains_key(s[i]) or ans[word_index]) {
                return;
            }
            curr_node=curr_node->get_next_node(s[i]);
            if(curr_node->is_end()) {
                solve(word_index,i+1,concat+1,root,s,ans);
            }
        }    
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        vector<bool>ans(n,false);
        vector<string>valid_words;
        for(auto i:words) {
            insert(i);
        }
        for(int i=0;i<n;i++) {
            solve(i,0,0,root,words[i],ans);
            if(ans[i]) {
                valid_words.emplace_back(words[i]);
            }     
        }
        return valid_words;
    }
};