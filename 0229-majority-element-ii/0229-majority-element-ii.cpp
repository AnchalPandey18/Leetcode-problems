class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 =0, cnt2 =0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(auto it:nums) {
            if(cnt1 == 0 && el2 != it){
                cnt1 =1;
                el1 = it;
            }
            else if(cnt2 == 0 && el1 != it) {
                cnt2 =1;
                el2 = it;
            }
            else if(el1 == it) {
                cnt1++;
            }
            else if(el2 == it) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ls;
        cnt1 =0,cnt2 = 0;
        for(int i=0;i<n;i++) {
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        int mini = (int)(n/3)+1;
        if(cnt1 >= mini) ls.push_back(el1);
        if(cnt2 >= mini) ls.push_back(el2);
        sort(ls.begin(),ls.end());
        return ls;
    }
};