// class Solution {
// public:
//     int distinctEchoSubstrings(string text) {
//         int n=text.size(),ans=0;
//         set<string>distinct;
//         for(int len=2;len<=n;len+=2) {
//             for(int i=0;i+len<=n;i++) {
//                 string st=text.substr(i,len);
//                 if(st.substr(0,len/2)==st.substr(len/2,len/2)) {
//                     distinct.insert(st);
//                 }
//             }
//         }
//         return distinct.size();
//     }
// };
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>distinct;
        for(int len=1;len<=n/2;len++) {
            int count=0;
            for(int left=0,right=len;right<=n;left++,right++) {
                if(text[left]!=text[right]) {
                    count=0;
                }else {
                    count++;
                }
                if(count==len) {
                    distinct.insert(text.substr(left,len));
                    count-=1;
                }
            }
        }
        return distinct.size();
    }
};