class Solution {
public:
    //391. Perfect Rectangle
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;
        for(auto it:rectangles){
            m[{it[0],it[1]}]++;  //1 1   3 1
            m[{it[2],it[3]}]++;  //3 3    4 2
            m[{it[0],it[3]}]--; // 1 3    3 2
            m[{it[2],it[1]}]--;   // 3 1   4 1 
        }
        int c=0;
        for( auto it=m.begin();it!=m.end();it++){
            if(abs(it->second)==1){
                c++;
            }
            else if(abs(it->second)!=1&&it->second!=0){
                return false;
            }
        }
        return c==4; 
    }
};
