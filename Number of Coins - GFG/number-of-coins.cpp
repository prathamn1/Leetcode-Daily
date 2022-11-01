//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int m, int v) 
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(v+1));
	    for(int i=0;i<=m;i++) {
	        for(int j=0;j<=v;j++) {
	            if(j==0) {
	                dp[i][j]=0;
	            }else if(i==0) {
	                dp[i][j]=1000000;
	            }else if(j<coins[i-1]) {
	                dp[i][j]=dp[i-1][j];
	            }else {
	                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	            }
	        }
	    }
	    return (dp[m][v]==1000000) ?-1 :dp[m][v];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends