//in this question first for making the string b from a we have to make count of the element of a equal to frequency of that element in b so every element in a must be a part of b or set of a == set of b
// now for conversion of frequency or operation 2 what we can do is just check that if we have the available frequencies to convert them to each other or 
//word1="cabbba", word2 = "abbccc"
//word1=[2,3,1], word2=[1,2,3]
//so we could see above that frequency count is same in word1 and word2 or sorted(word1)==sorted(word2) so we could make the frequency of word1 equal to word b by 2nd operation

//also char in word1 and word2 must be same

class Solution {
public:
    bool equals_array(int arr1[],int arr2[]) {
        for(int i=0;i<26;i++) {
            if(arr1[i]!=arr2[i]) {
                return false;
            }
        }
        return true;
    }
    bool closeStrings(string word1, string word2) {
        int freq1[26]={0},freq2[26]={0},is_present1[26]={0},is_present2[26]={0};
        for(auto i:word1) {
            freq1[i-'a']++;
            is_present1[i-'a']=1;
        }
        for(auto i:word2) {
            freq2[i-'a']++;
            is_present2[i-'a']=1;
        }
        sort(freq1,freq1+26);
        sort(freq2,freq2+26);
        return (equals_array(freq1,freq2) and equals_array(is_present1,is_present2)) ? true : false;
    }
};