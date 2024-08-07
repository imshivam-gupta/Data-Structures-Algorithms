#include<bits/stdc++.h>
using namespace std;

class CoinCombinationsI {
public:
    static const int MOD = 1e9+7;

    static int distinctOrderedWays(int desiredSum, const std::vector<int>& coins) {
        // dp[i] = number of ordered ways to make sum i
        // dp[i] = dp[i] + dp[i - coin]
        // base case: dp[0] = 1

        vector<int> dp(desiredSum + 1, 0);
        dp[0] = 1;

        for (int currMoney = 0; currMoney <= desiredSum; ++currMoney) {
            for (int coin : coins) {
                // int coin = coins[]
                if (currMoney - coin >= 0) {
                    dp[currMoney] = (dp[currMoney] + dp[currMoney - coin]) % MOD;
                }
            }
        }

        return dp[desiredSum];
    }
};