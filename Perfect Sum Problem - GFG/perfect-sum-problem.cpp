//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int>nums;
	    int multi=1,mod=1000000007;
	    for(int i=0;i<n;i++) {
	        if(arr[i]!=0) {
	            nums.emplace_back(arr[i]);
	        }else {
	            multi*=2;
	        }
	    }
	    int len=nums.size();
        vector<vector<int>>dp(len+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=len;i++) {
            for(int j=0;j<=sum;j++) {
                if(j==0) {
                    dp[i][j]=1;
                }else if(nums[i-1]>j) {
                    dp[i][j]=(dp[i-1][j])%mod;
                }else {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%mod;
                }
            }
        }
        // for(auto i:dp) {
        //     for(auto j:i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return (dp[len][sum]%mod*multi%mod)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends