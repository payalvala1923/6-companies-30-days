class Solution {
public:
    //1593. Split a String Into the Max Number of Unique Substrings
    unordered_set<string> st;
    int ans=INT_MIN;
    int maxUniqueSplit(string s) 
    {
       int c=0;
       fun(s,c);
       return ans;
    }
    void fun(string s,int c)
    {
       
        if(s.length()==0)
        {
            ans=max(ans,c);
            return;
        }
        string first="";
        string second="";

        for(int i=0;i<s.length();i++)
        {
            first.push_back(s[i]);

            if(st.find(first)==st.end())  
            {
                st.insert(first);
                second = s.substr(i+1,s.length());
                fun(second,c+1);
                st.erase(first);         
            }	
            else
            {
                continue;
            }
        }
    }
};
