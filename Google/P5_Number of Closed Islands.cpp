class Solution {
public:
  //1254. Number of Closed Islands
    bool dfs(vector<vector<int>>& g, int i, int j){
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){
            return false;
        }
        if (g[i][j] == 1){
            return true;
        }
        g[i][j] = 1;
        bool down = dfs(g, i+1, j);
        bool right = dfs(g, i, j+1);
        bool top = dfs(g, i-1, j);
        bool left = dfs(g, i, j-1);
        return down && top && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0){
                    if(dfs(grid, i, j)) ans++;
                }
            }
        }
        return ans;
    }
    
};
