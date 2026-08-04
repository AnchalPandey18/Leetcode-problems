class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxprod = nums[0];
        int minprod = nums[0];
        for(int i=1;i<nums.size();i++){
            int cur = nums[i];
            if(cur < 0) {
                swap(maxprod,minprod);
            }
            maxprod = max(cur,cur*maxprod);
            minprod = min(cur,cur*minprod);
            res = max(res,maxprod);
        }
        return res;
    }
};