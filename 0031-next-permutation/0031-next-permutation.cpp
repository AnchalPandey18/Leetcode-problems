class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int golaindex = -1;
        
        for(int i=n-1;i>0;i--) {
            if(nums[i-1]<nums[i]) {
                golaindex = i-1;
                break;
            }
        }
        int swapi = golaindex;
        if(golaindex !=-1) {
         for(int j=n-1;j>=golaindex+1;j--) {
            if(nums[j] > nums[golaindex]) {
                swapi =j;
                break;
            }
         }
         swap(nums[golaindex],nums[swapi]);
        }
        reverse(nums.begin() + golaindex+1, nums.end());
    }
};