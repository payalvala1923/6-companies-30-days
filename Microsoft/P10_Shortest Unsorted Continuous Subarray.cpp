class Solution {
public:
    //581. Shortest Unsorted Continuous Subarray
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int i1=-1,i2=-1;
        for(int i:nums)
            v.push_back(i);
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=v[i])
            {
                i1=i;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(v[j]!=nums[j])
            {
                i2=j;
                break;
            }
        }
        if(i1==-1 or i2==-1)
            return 0;
        return i2-i1+1;

    }
};
