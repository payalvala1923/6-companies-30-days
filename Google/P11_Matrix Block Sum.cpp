class Solution {
public:
    //1314. Matrix Block Sum
    int x, y;
    int fun(int i, int j, const vector<vector<int> >& sum) {
        if (i < 0 || j < 0) return 0;
        if (i >= x) 
            i = x - 1;
        if (j >= y) 
            j = y- 1;
        return sum[i][j];
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        x = mat.size();
        y = mat[0].size();
        
        vector<vector<int>> sum(x, vector<int>(y, 0));
        
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                sum[i][j] = mat[i][j] + fun(i-1, j, sum) + fun(i, j-1, sum) - fun(i-1, j-1, sum);
            }
        }
        
        
        vector<vector<int>> ans(x, vector<int>(y, 0));
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ans[i][j] = fun(i+K, j+K, sum) - fun(i+K, j-K-1,sum) 
                - fun(i-K-1, j+K, sum) + fun(i-K-1, j-K-1, sum);
            }
        }
        
        return ans;
    }
};
