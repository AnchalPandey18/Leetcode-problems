class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long reversed =0;
        while(x>0){
            int digit =x%10;
            reversed = reversed * 10 + digit;
          x /=10;
        } 
        return (original == reversed);
    }
};