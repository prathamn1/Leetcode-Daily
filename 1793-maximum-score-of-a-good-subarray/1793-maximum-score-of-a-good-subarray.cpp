//this question is all same as largest rectangle area in a histogram as here consider the heights as the value given in nums but there is one condition that the rectangle we have chosen must contain a pillar with index==k

// so here we are using a different implementation , instead of previously calculating left and right smaller in two loop-runs we will be calculating it in a single run with the final ans.

// so we have created a stack which will be monotonic increasing.we will keep traversing heights from beginning and whenever we find the heights[i]< stack.top(), since our stack was always in ascending order , it means that the right_smaller of  current top stack element will be the current i as it is the first element which is smaller than the current st.top() element.
// also the left_smaller element of the current_top element in stack will be the element on the top of stack after popping out the current element as the stack is increasing order so the first element to left smaller than the curr_top element will be the element stored just below it.
class Solution {
public:
    int maximumScore(vector<int>& heights, int k) {
        stack<int>st;
        st.push(-1); //in c++ we could check for empty() but in python -1 will refer to last element for easy implementation so that we don't need to check whether our stack is empty or not and it will also serve as the left smaller index if the stack becomes empty
        heights.push_back(0);// if the stack is in all increasing order then we will just keep adding element in the stack without calculating our area in one loop so we initiate a check for atleast calculating the area one time during our iteration.
        int ans=0;
        for(int i=0;i<heights.size();i++) {
            while(st.top()!=-1 and heights[i]<heights[st.top()]) {
                int curr_height=heights[st.top()];
                st.pop();
                int left_smaller=st.top();
                int right_smaller=i;
                if(left_smaller<k and k<right_smaller) {
                    ans=max(ans,curr_height*(right_smaller-left_smaller-1));   
                }
            }
            st.push(i);
        }
        heights.pop_back();
        return ans;
    }
};