class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increase = 1;
        int decrease = 1;
        int maxlen = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                increase++;
                decrease =1;
            }
            else if(nums[i+1]<nums[i]){
                decrease++;
                increase = 1;
            }
            else{
                increase = 1;
                decrease =1;
            }
            maxlen = max(maxlen,max(increase,decrease));
        }
        return maxlen;
    }
};