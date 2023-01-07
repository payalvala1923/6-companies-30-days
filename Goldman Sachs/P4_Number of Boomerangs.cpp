class Solution {
public:
    //447. Number of Boomerangs
    int distance(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int c = 0, n = points.size();
        for(int i = 0; i < n; i++)
        {
            map<int, int> mp;
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                
                int t = distance(points[i], points[j]);
                if(mp.find(t) != mp.end())
                    c += mp[t] * 2; 
                
                mp[t]++;
            }
        }
         
        return c;
    }
    
    
};
