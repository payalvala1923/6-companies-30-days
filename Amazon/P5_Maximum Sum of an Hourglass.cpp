class Solution {
public:
//2428. Maximum Sum of an Hourglass
    int maxSum(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(j>0 && j<m-1 && i<n-2){
                    int sum=grid[i][j]+grid[i][j-1]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};
//int sum=grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1];
