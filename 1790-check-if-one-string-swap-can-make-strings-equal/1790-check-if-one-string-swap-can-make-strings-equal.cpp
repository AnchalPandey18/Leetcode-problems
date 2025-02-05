class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1==s2)  return true;
        int n = s1.size();
        int m = s2.size();
        int mis = 0;
        int pos =0;
        vector<int>mismatch;
        while(pos<m){
            if(s1[pos] != s2[pos]){
              mismatch.push_back(s1[pos]);
              mismatch.push_back(s2[pos]);
              mis++;
            }
            if(mis>2) return false;
            pos++;
        }
        if(mismatch.size()==4){
            return (mismatch[0]==mismatch[3] && mismatch[1]==mismatch[2]);
        }
        return false;
    }
};