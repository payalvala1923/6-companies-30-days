class Solution {
public:
    //1358. Number of Substrings Containing All Three Characters
    int numberOfSubstrings(string s) {
        int c=0, j=0;

        vector<int>v(3, 0);

        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            while(v[0] && v[1] && v[2]){
                c+=s.size()-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return c;
    }
};
