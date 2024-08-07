#include<bits/stdc++.h>
using namespace std;

class BookShop {
public:

    static int maximumPages(vector<int> price,vector<int> pages,int maxTotalPrice) {
        // dp[x]: maximum pages with current price
        // dp[x]: for each book-> currpage+dp[i-x] and then take max
        // dp[0] =0

        int numBooks = price.size();
        vector<int> dp(maxTotalPrice+1,0);

        for(int i=0;i<numBooks;i++) {
            for(int currPrice=maxTotalPrice;currPrice>=0;currPrice--) {
                if(currPrice-price[i]>=0) {
                    dp[currPrice] = max(dp[currPrice], pages[i]+dp[currPrice-price[i]]);
                }
            }
        }

        return dp[maxTotalPrice];
    }
};