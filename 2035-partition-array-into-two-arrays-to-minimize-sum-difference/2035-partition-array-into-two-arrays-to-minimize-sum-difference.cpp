class Solution {
public:
    int minimumDifference(vector<int>& nums) {
      int n = nums.size()/2;
      unordered_map<int, vector<long long>>leftMap;
      unordered_map<int, vector<long long>>rightMap;
      long long total = 0;
      for(int i=0;i<nums.size();i++){
        total += nums[i];
      }
      // left half
      for(int mask = 0; mask < (1<<n); mask++){
        long long sum =0;
        int cnt =0;
        for(int i=0;i<n;i++) {
            if(mask & (1<<i)) {
                sum += nums[i];
                cnt++;
            }
        }
        leftMap[cnt].push_back(sum);
      }
      // right half
      for(int mask =0; mask < (1<<n); mask++) {
        long long sum =0;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                sum += nums[n+i];
                cnt++;
            }
        }
        rightMap[cnt].push_back(sum);
      }
      //  sort rightmap
      for(int i=0;i<=n;i++){
        sort(rightMap[i].begin(),rightMap[i].end());
      }

      long long ans = LLONG_MAX;
      for(int leftcnt = 0;leftcnt<=n;leftcnt++){
        int rightcnt = n-leftcnt;
        for(long long leftsum:leftMap[leftcnt]) {
            long long target = total/2 - leftsum;
            // binary search to find nearest rightsum in right half
            int low =0;
            int high = rightMap[rightcnt].size()-1;

            while(low<=high){
                int mid = low + (high-low)/2;
                if(rightMap[rightcnt][mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid-1;
                }
            }

            if(low < rightMap[rightcnt].size()) {
                long long selected = leftsum + rightMap[rightcnt][low];

                long long dif = llabs(total-2*selected);
                ans = min(ans,dif);
            }

            if(low>0) {
                long long selected= leftsum + rightMap[rightcnt][low-1];
                long long dif = llabs(total - 2*selected);
                ans = min(ans,dif);
            }
        }
      }
      return ans;
        }
};