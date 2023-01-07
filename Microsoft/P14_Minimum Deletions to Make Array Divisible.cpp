class Solution {
public:
    //2344. Minimum Deletions to Make Array Divisible
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
        
        int gcd=numsDivide[0];

        for(int i=1; i<numsDivide.size(); i++){
            gcd=__gcd(gcd, numsDivide[i]);
        }
        int c=0;
        if(nums[0]>gcd)
            return -1;
        for(int i=0; i<nums.size(); i++){
            if(gcd%nums[i]==0){
                return c;
            }
            c++;
        }
        return -1;
    }
};
