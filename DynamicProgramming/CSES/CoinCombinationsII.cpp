#include<bits/stdc++.h>
using namespace std;

class CoinCombinationsII {
public:
    static const int MOD = 1e9+7;

    static int distinctWays(int desiredSum, const std::vector<int>& coins) {
        // dp[i] = number of ways to make sum i
        // dp[i] = dp[i] + dp[i - coin]
        // additional constraint ci<ci+1 and all ci's are picked together
        // base case: dp[0] = 1

        // final dp states
        // dp[i][k] = dp[i-1][k]+dp[i][k-ci]
        // BC: dp[i][0] =1

        vector<vector<int>> dp(coins.size(),vector<int>(desiredSum));

        for(int i=0;i<coins.size();i++) {
            dp[i][0]=1;
        }

        for(int i=0;i<coins.size();i++) {
            for(int sum = 1;sum<=desiredSum;sum++) {
                dp[i][sum] = (i > 0) ? dp[i-1][sum] : 0;

                if(sum - coins[i] >= 0) {
                    dp[i][sum] = (dp[i][sum] + dp[i][sum - coins[i]]) % MOD;
                }
            }
        }

        return dp[coins.size()-1][desiredSum];
    }
};