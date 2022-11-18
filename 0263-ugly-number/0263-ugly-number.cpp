class Solution {
public:
    bool check_prime(int num) {
        if(num==1) {
            return false;
        }else if(num==2) {
            return true;
        }else {
            for(int i=2;i*i<=num;i++) {
                if(num%i==0) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isUgly(int n) {
        //finding prime factors
        long long int i=2;
        while(i*i<=n) {
            if(check_prime(i)) {
                int temp=n;
                while(n%i==0) {
                    if(i!=1 and i!=2 and i!=3 and i!=5) {
                        return false;
                    }
                    n/=i;
                }
                if(n==temp) {
                    i+=1;
                }
            }else {
                i+=1;
            }
        }
        return n==1 or n==2 or n==3 or n==5;
    }
};