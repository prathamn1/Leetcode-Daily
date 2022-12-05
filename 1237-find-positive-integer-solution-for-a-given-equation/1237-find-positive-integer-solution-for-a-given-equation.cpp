/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int>>ans;
//         for(int x=1;x<=1000;x++) {
//             for(int y=1;y<=1000;y++) {
//                 if(customfunction.f(x,y)==z) {
//                     ans.push_back({x,y});
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>ans;
        for(int x=1;x<=1000;x++) {
            int low=1,high=1000,found=-1;
            while(low<=high) {
                int mid=(high+low)/2;
                int f_mid=customfunction.f(x,mid);
                if(f_mid==z) {
                    found=mid;
                    break;
                }else if(f_mid>z) {
                    high=mid-1;
                }else {
                    low=mid+1;
                }
            }
            if(found!=-1) {
                for(int y=found;y<=1000 and customfunction.f(x,y)==z;y++) ans.push_back({x,y});
                for(int y=found-1;y>=0 and customfunction.f(x,y)==z;y--) ans.push_back({x,y});
            }
        }
        return ans;   
    }
};