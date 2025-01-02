class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int>ans(m);
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int>prefixSum(n);
        int sum  =0;
        for(int i = 0;i<n;i++){
            string curWord = words[i];
            if(vowels.count(curWord[0]) && vowels.count(curWord[curWord.size()-1])){
                sum++;
            }
            prefixSum[i] = sum;
        }
        for(int i=0; i<m ; i++){
            vector<int>curQuery = queries[i];
            ans[i] = prefixSum[curQuery[1]] - (curQuery[0] == 0 ? 0 : prefixSum[curQuery[0]-1]);
        }
        return ans;
    }
};