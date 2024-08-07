#include <bits/stdc++.h>
using namespace std;

class MinimizingCoins {
public:
    static int minimumCoins(int desiredSum,vector<int> coins) {
        // dp[currMoney] -> minimum coins required to generate current money
        // dp[currMoney] = min(dp[currMoney],1+dp[currMoney-coins[i]])

        vector<int> dp(desiredSum + 1, INT_MAX);
        dp[0] = 0;

        for (int currMoney = 0; currMoney <= desiredSum; ++currMoney) {
            for (int coin : coins) {
                if (currMoney - coin >= 0 && dp[currMoney - coin] != INT_MAX) {
                    dp[currMoney] = min(dp[currMoney],1+dp[currMoney - coin]);
                }
            }
        }

        return (dp[desiredSum]!=INT_MAX)?dp[desiredSum]:-1;
    }
};

