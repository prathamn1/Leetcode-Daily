class Solution {
public:
    void calculate_part(stack<string>&st){
        long long int op1=0;
        while(not st.empty() and st.top()!="(" ) {
            long long int op2=stoll(st.top());
            st.pop();
            if(st.top()=="-") {
                op2*=-1;
            }
            st.pop();
            op1+=op2;
        }
        if(not st.empty()) {
            st.pop();
        }
        st.push(to_string(op1));
    }
    
    
    int calculate(string s) {
        stack<string>st;
        int n=s.size();
        if(s[0]!='-') {
            st.push("+");
        }
        int i=0;
        unordered_set<char>not_numbers={'+','-',' ',')','('};
        while(i<n) {
            if(not st.empty() and st.top()=="(" and s[i]!=' ' and s[i]!='-') {
                st.push("+");
            }
            if(s[i]==')') {
                calculate_part(st);
            }else if(s[i]!=' '){
                string ch;
                if(not_numbers.find(s[i])!=not_numbers.end()) {
                    ch+=s[i];
                }else {
                    while(i<n and not_numbers.find(s[i])==not_numbers.end()) {
                        ch+=s[i];
                        i+=1;
                    }
                    i-=1;
                }
                st.push(ch);   
            }
            i+=1; 
        }
        calculate_part(st);
        return stoll(st.top());
    }
};