// //observation ->  in the optimal answer we must note that one pillar of histogram will be taken in total so first we will pre_compute the next strictly smaller element to left and right.

// // using each row of matrix as a individual histogram with the height of column = consecutive '1's inclusive the present one.
// class Solution {
// public:
//     vector<int> find_next_smaller_element(vector<int>& heights,int n,int start,int stop, int dir) {
//         vector<int>next_smaller(n);
//         stack<int>st;
//         for(int i=start;i!=stop;i+=dir) {
//             while(not st.empty() and heights[i]<=heights[st.top()]) {
//                 st.pop();
//             }
//             if(not st.empty()) {
//                 next_smaller[i]=st.top();
//             }else {
//                 if(dir==-1) {
//                    next_smaller[i]=n; // for next_greater element to right
//                 }else {
//                     next_smaller[i]=-1;// for next_smaller element to left
//                 }
//             }
//             st.push(i);
//         }
//         return next_smaller;
//     } 
//     // void print_vector(vector<int>arr) {
//     //     for(auto i:arr) {
//     //         cout<<i<<" ";
//     //     }
//     //     cout<<"\n";
//     // }
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         vector<int>next_smaller_left,next_smaller_right;
//         next_smaller_left=find_next_smaller_element(heights,n,0,n,1);
//         next_smaller_right=find_next_smaller_element(heights,n,n-1,-1,-1);
//         // print_vector(next_smaller_left);
//         // print_vector(next_smaller_right);
//         int ans=0;
//         for(int i=0;i<n;i++) {
//             int l=next_smaller_left[i],r=next_smaller_right[i];
//             ans=max(ans,(r-l-1)*heights[i]);
//         }
//         return ans;
//     }
// };



// so here we are using a different implementation , instead of previously calculating left and right smaller in two loop-runs we will be calculating it in a single run with the final ans.

// so we have created a stack which will be monotonic increasing.we will keep traversing heights from beginning and whenever we find the heights[i]< stack.top(), since our stack was always in ascending order , it means that the right_smaller of  current top stack element will be the current i as it is the first element which is smaller than the current st.top() element.
// also the left_smaller element of the current_top element in stack will be the element on the top of stack after popping out the current element as the stack is increasing order so the first element to left smaller than the curr_top element will be the element stored just below it.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
                ans=max(ans,curr_height*(right_smaller-left_smaller-1));   
            }
            st.push(i);
        }
        heights.pop_back();
        return ans;
    }
};
