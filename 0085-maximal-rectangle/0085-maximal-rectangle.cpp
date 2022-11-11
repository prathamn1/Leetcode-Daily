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
    
    void convert_to_histogram_row(vector<vector<int>> &grid,vector<vector<char>>& matrix,int m,int n) {
        for(int j=0;j<n;j++) {
            for(int i=0;i<m;i++) {
                if(matrix[i][j]=='0') {
                    grid[i][j]=0;
                }else if(i==0) {
                    grid[i][j]=1;
                } else{
                    grid[i][j]=1+grid[i-1][j];
                }
            }
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<vector<int>>grid(m,vector<int>(n));
        convert_to_histogram_row(grid,matrix,m,n);
        for(int i=0;i<m;i++) {
            ans=max(ans,largestRectangleArea(grid[i]));
        }
        return ans;
    }
};