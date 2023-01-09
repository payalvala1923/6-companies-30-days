class Solution {
public:
    //2260. Minimum Consecutive Cards to Pick Up
    int minimumCardPickup(vector<int>& cards) {
        int mn= INT_MAX;
        map<int,int> mp;
        for (int i=0; i<cards.size(); i++){
            if (mp.find(cards[i]) != mp.end()){
                mn= min(mn,i-mp[cards[i]]+1);
            }
            mp[cards[i]]= i;
        }
       if(mn==INT_MAX) return -1;
        return mn;
    }
};
