class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>ans;
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int ptr = 0, x = 0, y = 0;
        ans.push_back(matrix[x][y]);
        matrix[x][y] = -101;
        while(ans.size()<m*n){
            int newX = x + dir[ptr][0];
            int newY = y + dir[ptr][1];
            if(newX>=0 and newX<m and newY>=0 and newY<n and matrix[newX][newY]!=-101){
                x = newX;
                y = newY;
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -101;
            }else{
                ptr++;
                ptr%=4;
            }
        }
        return ans;
    }
};
