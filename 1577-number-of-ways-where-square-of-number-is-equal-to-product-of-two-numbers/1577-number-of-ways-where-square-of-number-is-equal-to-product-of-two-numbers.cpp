
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long int ,long long int>squares1,squares2;
        int n1=nums1.size(),n2=nums2.size(),ans=0;
        long long int pr,sq;
        for(long long int i:nums1) {
            sq=i*i;
            squares1[sq]++;
        }
        for(long long int i:nums2) {
            sq=i*i;
            squares2[sq]++;
        }
        for(int i=0;i<n1;i++) {
            for(int j=i+1;j<n1;j++) {
                pr=(long long int)nums1[i]*nums1[j];
                if(squares2.find(pr)!=squares2.end()) {
                    ans+=squares2[pr];
                }
            }
        }
        for(int i=0;i<n2;i++) {
            for(int j=i+1;j<n2;j++) {
                pr=(long long int)nums2[i]*nums2[j];
                if(squares1.find(pr)!=squares1.end()) {
                    ans+=squares1[pr];
                }
            }
        }
        return ans;
    }
};