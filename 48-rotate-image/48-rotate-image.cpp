/*
operation                                degree
transpose and swap half columns           90
swap all rows and then all columns        180
transpose and swap rows                   270
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++) {
            for(int j=i;j<matrix[0].size();j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size()/2;j++) {
                swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
            }
        }
    }
};