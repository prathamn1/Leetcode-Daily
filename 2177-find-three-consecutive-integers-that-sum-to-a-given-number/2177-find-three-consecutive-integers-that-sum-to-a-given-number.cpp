class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3==0) {
            long long k=num/3;
            return {k-1,k,k+1};
        }
        return {};
    }
};