#include<bits/stdc++.h>
using namespace std;

class DiceCombinations {
public:
    static const int MOD = 1e9+7;

    static int countWays(int desiredSum) {
        // dp(n) -> ways to get n by throwing dice
        // dp(n) -> // dp(n-1)...dp(n-6) +1 from each but if possible then only
        // 0->0   1->1    2  1+1 2

        vector<int> dp(desiredSum + 1, 0);
        dp[0] = 1;

        for (int currMoney = 0; currMoney <= desiredSum; ++currMoney) {
            for (int dice = 1; dice <= 6; ++dice) {
                if (currMoney - dice >= 0) {
                    dp[currMoney] = (dp[currMoney] + dp[currMoney - dice]) % MOD;
                }
            }
        }

        return dp[desiredSum];
    }
};