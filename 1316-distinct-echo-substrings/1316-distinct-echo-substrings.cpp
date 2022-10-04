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
                    count-=1; // it's a catch suppose we have a string to check that is 'abcabcabc' so easily we could have found our first match and at that time our l=2 and r=5 but after that we have to remove the first character that is we should now start checking from 'b'(index 1) , but isn't it necessary as we have just checked 'bc' so we will just decrement our count by 1 to check for next character after 'bc' i.e. 'a'.
                }
            }
        }
        return distinct.size();
    }
};