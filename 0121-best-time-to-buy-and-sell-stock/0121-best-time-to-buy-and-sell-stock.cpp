class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxi =0;
        for(int price:prices) {
            if(price<minprice) {
                minprice = price;
            }
            else {
                maxi = max(maxi,price-minprice);
            }
        }
        return maxi;
    }
};