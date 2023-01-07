class Solution {
public:
    //593. Valid Square
    int distance(vector<int>& p1, vector<int>& p2){
        int dist=((p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]));
        return dist;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts = {p1, p2, p3, p4};
        set<double> st;
        for(int i = 0 ; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                double val = distance(pts[i], pts[j]);
                
                if(val != 0)
                    st.insert(val);
               
                else
                    return false;
            }
        }
      
        return st.size() == 2;
    }
};
