//F(k) = a U b U c =a+b+c - aIb - bIc -cIa +aIbIc
//so we need to find the smallest k where f(k)>=n
// where a =no.s <=n divisible by a
// where b =no.s <=n divisible by b
// where c =no.s <=n divisible by c
// where aIb =no.s <=n divisible by lcm(a,b)
// where bIc =no.s <=n divisible by lcm(b,c)
// where cIa =no.s <=n divisible by lcm(c,a)
// where aIbIc =no.s <=n divisible by lcm(a,b,c)


class Solution {
public:

    int nthUglyNumber(int n, int a, int b, int c) {
        long long low=1,high=2*1e9;
        long long int A=long(a),B=long(b),C=long(c);
        long long int aLb=lcm(A,B),bLc=lcm(B,C),cLa=lcm(C,A),aLbLc=lcm(A,lcm(B,C));
        while(low<high) {
            long long int mid=low+(high-low)/2;
            long long int F_mid=mid/A+mid/B+mid/C - (mid/aLb+mid/bLc+mid/cLa)+mid/aLbLc;
            if(F_mid<n) {
                low=mid+1;
            }else {
                high=mid;
            }
        }
        return low;
    }
};