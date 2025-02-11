class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        string result;
        for(char c:s){
            result.push_back(c);
            if(result.size()>=n && result.substr(result.size() - n) == part){
                result.erase(result.size() - n , n);
            }
        }
        return result;
    }
};