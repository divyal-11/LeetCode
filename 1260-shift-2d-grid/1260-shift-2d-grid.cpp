class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();//row
        int n = grid[0].size();//col

        vector<vector<int>> ans(m,vector<int>(n));

        int total = m*n;
        k = k%total;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldidx = i*n + j;//convert to 1d idx
                int newidx = (oldidx +k) % total;//after shifting

                int newR = newidx/n;//fir row divide with no. of cols
                int newC = newidx%n;// for column number take the modulo with no. of cols

                ans[newR][newC] = grid[i][j];
            }
            
        }
        return ans;
    }
};