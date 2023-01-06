class Solution {
public:
    //207. Course Schedule
    bool dfs(vector<vector<int>>&adj, int node, vector<int>&vis){
        vis[node] = 1;
        for(int child: adj[node]){
            if(vis[child] == 2)
                continue;
            if(vis[child] == 1)
                return false;
            if(!dfs(adj, child, vis))
                return false;
        }
        vis[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(numCourses);
        for(auto v: prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(!dfs(adj, i, vis))
                    return false;
            }
        }
        return true;
    }
    
};
