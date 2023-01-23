class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        map<int,int> mp;
        mp[bottom]=0;
        mp[top]=0;
        for(int i:special){
            mp[i]=1;
        }
        int k=0,ans=0,  x,y;
        for(auto i:mp){
            if(k==0){
                k++;
                x=i.first;
                y=i.second;
            }
            else{
                if(y==1 && i.second==1){
                    ans=max(ans,i.first-x-1);
                }
                else
                    ans=max(ans,i.first-x);

                x=i.first;
                y=i.second;
            }
        }
        return ans;
    }
};
