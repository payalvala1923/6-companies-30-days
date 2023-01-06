class Solution {
public:
    //396. Rotate Function
    int maxRotateFunction(vector<int>& nums) {

        long sum=0, f=0;

        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            f+=i*nums[i] ;
        }

        long mx=f;

        for(int i=(nums.size()-1);i>=0;i--){
            f += sum - (nums[i]* nums.size());
            mx= max(mx,f);
        }
        return mx;
    }
};
