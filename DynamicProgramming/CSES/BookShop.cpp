#include<bits/stdc++.h>
using namespace std;

class BookShop {
public:

    static int maximumPages(vector<int> price,vector<int> pages,int maxTotalPrice) {
        // dp[i,x] -> i is current index and x is money remaining to spend
        // dp[0,w] -> ans to our problem
        // dp[i,x] - max(dp[i+1,x],pages[i]+dp[i+1,x-cost[i]])

        int numBooks = price.size();
        vector<vector<int>> dp(numBooks+1,vector<int>(maxTotalPrice+1,0));

        for(int i=numBooks-1;i>=0;i--) {
            for(int j=0;j<=maxTotalPrice;j++) {
                dp[i][j]  = dp[i+1][j];
                if(j-price[i]>=0) {
                    dp[i][j] = max(dp[i][j],pages[i]+dp[i+1][j-price[i]]);
                }
            }
        }

        return dp[0][maxTotalPrice];
    }
};