class Solution {
public:
//1947. Maximum Compatibility Score Sum
    int vis[9] = {}, ans = 0, x, y;
    void dfs(vector<vector<int>>& s, vector<vector<int>>& m, int i, int score) {
        if (i == x) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < x; ++j) {
            if (vis[j]) continue;
            vis[j] = 1;
            int sum = 0;
            for (int k = 0; k < y; ++k) 
                sum += (s[i][k] == m[j][k]); 
            dfs(s, m, i + 1, score + sum);
            vis[j] = 0;
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& student, vector<vector<int>>& mentor) {
        x = student.size(), y = student[0].size();
        dfs(student, mentor, 0, 0);
        return ans;
    }
};
