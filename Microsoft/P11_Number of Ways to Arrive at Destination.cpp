class Solution {
public:
    //1976. Number of Ways to Arrive at Destination
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];

        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dis(n, LONG_MAX);
        vector<long long> ways(n);
        
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        long long mod = 1e9+ 7;
        
        while(!pq.empty()){
            
            long long nw = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
                
        
            for(auto i: adj[node]){
                
                long long child = i.first;
                long long cw = i.second;
                
                if(cw + nw < dis[child]){
                    dis[child] = cw + nw;
                    pq.push({dis[child], child});
                    ways[child] = ways[node];
                }
                else if(cw + nw == dis[child]){
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
          
    }
};
