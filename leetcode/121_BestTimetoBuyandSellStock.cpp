class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<int> f(n,0);
        int minprice=prices[0];
        for(int i=0; i<n; i++) {
            minprice=min(minprice, prices[i]);
            f[i]=prices[i]-minprice;
        }
        int profit=f[0];
        for(int i=0; i<n; i++)
            profit=max(profit, f[i]);
        return profit;
    }
};
