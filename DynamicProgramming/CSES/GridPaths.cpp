#include <bits/stdc++.h>
using namespace std;

class GridPaths {
public:
    static const int MOD = 1e9+7;

    static int countPaths(vector<string> grid) {
        // dp[i][j] ways from i,j to lowe right
        // dp[i][j] = dp[i+1][j] + dp[i][j+1] : not a trap if else 0
        // dp[n-1][m-1] :1

        int n = grid.size(), m=grid[0].size();
        if(grid[0][0]=='*' or grid[n-1][m-1]=='.') {
            return 0;
        }

        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1] = (grid[n-1][m-1] != '*' ) ? 1 : 0;

        for(int i=n-1;i>=0;i--) {
            for(int j=m;j>=0;j--) {

                if(i==n-1 and j==m-1) {
                    continue;
                }

                if(grid[i][j]!='*'){
                    int waysDown = (i<n-1)?dp[i+1][j]:0;
                    int waysRight = (j<m-1)?dp[i][j+1]:0;
                    dp[i][j] = (waysRight+waysDown)%MOD;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }
};

