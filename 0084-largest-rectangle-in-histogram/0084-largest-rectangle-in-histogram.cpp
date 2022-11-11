//observation ->  in the optimal answer we must note that one pillar of histogram will be taken in total so first we will pre_compute the next strictly smaller element to left and right.

// using each row of matrix as a individual histogram with the height of column = consecutive '1's inclusive the present one.
class Solution {
public:
    vector<int> find_next_smaller_element(vector<int>& heights,int n,int start,int stop, int dir) {
        vector<int>next_smaller(n);
        stack<int>st;
        for(int i=start;i!=stop;i+=dir) {
            while(not st.empty() and heights[i]<=heights[st.top()]) {
                st.pop();
            }
            if(not st.empty()) {
                next_smaller[i]=st.top();
            }else {
                if(dir==-1) {
                   next_smaller[i]=n; // for next_greater element to right
                }else {
                    next_smaller[i]=-1;// for next_smaller element to left
                }
            }
            st.push(i);
        }
        return next_smaller;
    } 
    // void print_vector(vector<int>arr) {
    //     for(auto i:arr) {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next_smaller_left,next_smaller_right;
        next_smaller_left=find_next_smaller_element(heights,n,0,n,1);
        next_smaller_right=find_next_smaller_element(heights,n,n-1,-1,-1);
        // print_vector(next_smaller_left);
        // print_vector(next_smaller_right);
        int ans=0;
        for(int i=0;i<n;i++) {
            int l=next_smaller_left[i],r=next_smaller_right[i];
            ans=max(ans,(r-l-1)*heights[i]);
        }
        return ans;
    }
};
