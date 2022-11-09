//actually we have to find the next greater element to the left of the current element so we are required to keep the count of current element index as we are getting just the element not the array so we will keep one counter for it and then traverse from the beginning and also we have to put the {INT_MAX,-1} in the stack as pair as we don't have the array so that we could access the element now  just traverse and if the current element is greater than the top of stack then pop it out and finally return the answer as (current element index - st.top().second i.e. the topmost element index)
class StockSpanner {
public:
    int curr_index;
    stack<pair<int,int>>st;
    StockSpanner() {
        curr_index=-1;
        st.push({INT_MAX,curr_index});
    }
    
    int next(int price) {
        curr_index++;
        while(price>=st.top().first) {
            st.pop();
        }
        int ans=curr_index-st.top().second;
        st.push({price,curr_index});
        return ans;   
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */