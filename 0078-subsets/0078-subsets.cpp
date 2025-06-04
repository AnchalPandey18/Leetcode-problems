class Solution {
public:
 void subsequence(vector<int> &nums, int i, vector<vector<int>> & ans,int n, vector<int> temp){
    if(i == n ){
        ans.push_back(temp);
        return;
    }
    subsequence(nums,i+1,ans , n,temp);
    temp.push_back(nums[i]);
      subsequence(nums,i+1,ans, n,temp);
     // temp.pop_back();

 }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp; 
      subsequence(nums,0,ans,nums.size(),temp);
      return ans;
    }
};