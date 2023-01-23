class Solution {
public:
    //912. Sort an Array
    vector<int> sortArray(vector<int>& nums) {
        //using min heap
       priority_queue<int, vector<int>, greater<int>> q;
		for(int i=0; i<nums.size(); i++){
			q.push(nums[i]);
		}
		vector<int> ans;
		while(!q.empty()){
			ans.push_back(q.top());
			q.pop();
		}
		return ans;
        
    }
};
