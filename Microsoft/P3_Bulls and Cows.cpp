;class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m1,m2;
        int bull=0,cow=0;
        for(int i=0;i<secret.size();++i){
            if(secret[i]==guess[i])
                bull++;
            else{
                m1[secret[i]-'0']++;
                m2[guess[i]-'0']++;
            }
        }
        for(auto i: m1){
            if(m2.find(i.first)!=m2.end()){
                cow=cow+min(i.second, m2[i.first]);
            }
        }

        string s=to_string(bull)+"A"+to_string(cow)+"B";
        return s;
    }
};
