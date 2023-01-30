#include<bits/stdc++.h>
#include<queue>
class Solution {

public:
    //692. Top K Frequent Words
    vector<string> topKFrequent(vector<string>& words, int k) {
        /*priority_queue<int,string> h;
        vector<string> v;
        map<string,int> mp; 
        for(int i=0;i<words.size();++i){
            mp[words[i]]++;
        }
        for(auto it:mp){
            h.push({it->second,it->first});
            if(h.size()>k)
            {
               h.pop();
            }
           }
        while(k--){
            v.push_back(h.top().second);
            h.pop();
         }
        return v;
        
         */
             
    unordered_map<string,int> mp;
    for(string s:words) mp[s]++;

    vector<pair<int,string>> t;
    vector<string> ans;

    for(auto it:mp){
        t.push_back({-it.second,it.first});
    }
    sort(t.begin(),t.end());

    for(int i=0;i<k;i++) ans.push_back(t[i].second);
    return ans;
      
    }
};
