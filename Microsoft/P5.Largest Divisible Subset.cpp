class Solution {
public:
    //368. Largest Divisible Subset
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int mx=1, prev=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int> v1(n, 1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){

                if(!(nums[i]%nums[j]) && v1[i]<v1[j]+1){
                    v1[i]=v1[j]+1;
                    if(mx<v1[i]){
                        mx=v1[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(mx==v1[i] && (prev==-1 || !(prev%nums[i]))){
                v.push_back(nums[i]);
                mx--;
                prev=nums[i];
            }
        }
        return v;
    }
};
