class Solution {
public:
    //2396. Strictly Palindromic Number
    bool isStrictlyPalindromic(int n) {
       int temp;
       string base;
       for(int i=2;i<n-1;++i){
           int temp=n;
           while(temp){
               base+=to_string(temp%i);
               temp/=i;
           }
           int s=0,e=base.size();
           while(s<e){
               if(base[s++]!=base[e--]) return false;
           }
           base="";
       }
       return true;
    }
};
