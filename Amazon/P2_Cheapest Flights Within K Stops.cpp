class Solution {
public:
    //787.Cheapest Flights Within K Stops
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto i: flights) 
            adj[i[0]].push_back({i[1], i[2]});
        vector<int> prices(n, -1);
        queue<pair<int, int>> q; 
        q.push({src, 0});
        ++k;
        while(!q.empty()) {
            if(!k) break;
            int l = q.size();
            for(int i = 0; i < l; i++) {
                auto c = q.front(); 
                q.pop();
                for(auto i: adj[c.first]) {
                    int price = c.second + i.second; 
                    if(prices[i.first] == -1 || price < prices[i.first]) {
                        prices[i.first] = price;
                        q.push({i.first, price});
                    }
                }
            }
            k--;
        }
        return prices[dst];
    }
};
