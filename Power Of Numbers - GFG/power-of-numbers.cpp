//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    #define mod 1000000007
    long long int solve(long long int x,long long int n) {
        if(x==0 or x==1) return x;
        if(n==0) return 1ll;
        if(n%2) return ((x%mod)*(solve(((x%mod)*(x%mod))%mod,(n-1)/2)%mod)%mod);
        return solve(((x%mod)*(x%mod))%mod,n/2);
    }
    
    
    long long power(int N,int R)
    {
        long long int temp=solve(N,R);
        return temp;
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends