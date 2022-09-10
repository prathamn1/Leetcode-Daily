class Solution {
    // keep count of profit in bs vector as
    // while buying take profit as negative for easy implementation and while selling take 
    // maximum of current profit value & previous profit+price value
    //while buying take minimum of like current profit value and previous value-price value
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 or prices.size()==0) {
            return 0;
        }
        vector<int>bs(k*2,0);
        for(int i=0;i<bs.size();i+=2) {
            bs[i]=INT_MAX;
        }
        for(int i=0;i<prices.size();i++) {
            bs[0]=min(bs[0],prices[i]);
            int j=1;
            while(j<bs.size()-1) {
                bs[j]=max(bs[j],prices[i]-bs[j-1]);
                j+=1;
                bs[j]=min(bs[j],prices[i]-bs[j-1]);
                j+=1;
            } 
            bs[j]=max(bs[j],prices[i]-bs[j-1]);
        }
        return bs[bs.size()-1];
    }
};