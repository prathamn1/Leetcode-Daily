class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int pos=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        vector<int>ans;
        int i,j;
        if(pos>=0 and pos<n and arr[pos]==x) {
            ans.push_back(arr[pos]);
            i=pos-1;
            j=pos+1; 
            k-=1;
        }else {
            i=pos-1;
            j=pos;
        }
        // cout<<i<<" "<<j;
        while(i>=0 and j<n and k>0) {
            if(abs(arr[i]-x)<=abs(arr[j]-x)) {
                ans.push_back(arr[i]);
                k-=1;
                i-=1;
            }else {
                ans.push_back(arr[j]);
                k-=1;
                j+=1;
            }
        }
        while(i>=0 and k>0) {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(j<n and k>0) {
            ans.push_back(arr[j]);
            j++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};