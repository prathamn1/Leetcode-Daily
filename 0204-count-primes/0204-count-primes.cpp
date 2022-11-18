class Solution {
public:
    
    int countPrimes(int n) {
        static vector<int>primes;
        if(primes.size()==0) {
           primes.resize(5*1000000+1,1);
           primes[0]=0;
           primes[1]=0;
           for(int i=2;i*i<=5*1000000;i++) {
               if(primes[i]) {
                   for(int j=2*i;j<=5*1000000;j+=i) {
                       primes[j]=0;
                   }
               }
           }
           for(int i=1;i<=5*1000000;i++) {
               primes[i]+=primes[i-1];
           }
        }
        if(n==0) {
            return 0;
        }
        return primes[n-1];
    }
};