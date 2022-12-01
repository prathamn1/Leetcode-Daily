// when the stack becomes empty we put the index after which there is a chance of getting valid substring.
//in starting as stack is empty so we put -1 as there is a chance of getting substring starting from 0
//let's say first element is ')' then also we will first pop out the top and then the stack will become empty and then after checking we will put the current index as after this index we may get the valid substring or first '('

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size(),ans=0;
        st.push(-1);
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                st.push(i);
            }else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }else {
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};