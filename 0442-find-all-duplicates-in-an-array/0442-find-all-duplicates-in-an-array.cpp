class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        // for(int i =1;i<nums.size();i++){
        //     if(nums[i] == nums[i-1]){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            }
            else {
                nums[index] = - nums[index];
            }
        }
        return ans;
    }
};