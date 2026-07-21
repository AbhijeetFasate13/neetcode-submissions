class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>firstCol;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            firstCol.push_back(matrix[i][0]);
        }
        int row = upper_bound(firstCol.begin(),firstCol.end(),target)-firstCol.begin();
        if(row==0 && matrix[0][0] != target) return false;
        if(row == 0) row = 1;
        int col = lower_bound(matrix[row-1].begin(),matrix[row-1].end(),target)-matrix[row-1].begin();
        if(col < 0 || col >= matrix[row-1].size()) return false;
        return matrix[row-1][col]==target;
    }
};
