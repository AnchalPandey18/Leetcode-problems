class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left=0, totalsum =0;
        for(int num:nums){
            totalsum = totalsum+num;
        }
        int count =-0;
        for(int i=0;i<nums.size()-1;i++){
            left = left+nums[i];
            totalsum = totalsum-nums[i];
            if(left>=totalsum){
                count++;
            }
        }
        return count;
    }
};