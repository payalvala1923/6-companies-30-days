class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k, int n, vector<int> v){
        if(v.size()==k && n==0){
            ans.push_back(v);
            return;
        }
        int start;
        if(v.empty()) start=1;
        else
            start=v.back()+1;
        for(int i=start ;i<10 ;++i){
            if(n-i<0)
                break;
            v.push_back(i);
            solve(k,n-i,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(k,n,v);
        return ans;
    }
};
