#include<bits/stdc++.h>
using namespace std;

class RemovingDigits {
public:

    static int countSteps(int n) {
        // dp[n]: steps to construct number n
        // dp[n] = iterate over digit: min(dp[n], 1+dp[n-digit])
        // BC: dp[0] = 1

        vector<int> dp(n+1,1e9);
        dp[0] = 0;

        for(int currNum=1;currNum<=n;currNum++) {
            int temp = currNum;
            while(temp) {
                if(currNum-temp%10>=0) {
                    dp[currNum] = min(dp[currNum],1+dp[currNum-temp%10]);
                    temp=temp/10;
                }
            }
        }

        return dp[n];
    }
};