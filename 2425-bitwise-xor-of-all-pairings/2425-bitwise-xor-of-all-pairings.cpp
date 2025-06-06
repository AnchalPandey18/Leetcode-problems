class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2  = nums2.size();
        int x1 =0;
        int x2 =0;
    if(n1 %2 != 0){
        for(int num: nums2){
            x2 ^= num;
        }
    }
    if(n2 % 2 !=0){
        for(int num: nums1){
            x1 ^= num;
        }
    }
    return x1 ^ x2;
    }
};