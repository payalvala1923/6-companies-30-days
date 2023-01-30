class Solution {
public:
    //1503. Last Moment Before All Ants Fall Out of a Plank
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(),right.end());
        int a,b;
        if(left.size()==0){
            a=0;
        }
        else{
            a=left[left.size()-1];
        }
        if(right.size()==0){
            b=n;
        }
        else{
            b=right[0];
        }
        return max(a,n-b);
    }
};
