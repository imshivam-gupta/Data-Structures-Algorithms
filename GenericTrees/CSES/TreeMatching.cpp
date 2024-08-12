#include<bits/stdc++.h>
using namespace std;

class TreeMatching {
public:

    static void solver(vector<vector<long long>> &adj,long long src,long long par,vector<vector<long long>> &dp) {
        dp[src][0] = dp[src][1] = 0;

        bool leaf = true;
        for(long long child:adj[src]) {
            if(child!=par) {
                leaf = false;
                solver(adj, child, src, dp);
            }
        }

        if(leaf) {
            return;
        }

        vector<long long> prefix, suffix;
        for(long long child: adj[src]) {
            if(child!=par) {
                prefix.push_back(max(dp[child][0],dp[child][1]));
                suffix.push_back(max(dp[child][0],dp[child][1]));
            }
        }

        for(long long i=1;i<prefix.size();i++) {
            prefix[i] += prefix[i-1];
        }

        for(long long i=suffix.size()-2;i>=0;i--) {
            suffix[i] += suffix[i+1];
        }

        dp[src][0] = suffix[0];

        long long childNum = 0;

        for(long long child : adj[src]) {
            if(child == par) {
                continue;
            }

            long long leftChildren = (childNum == 0) ? 0 : prefix[childNum - 1];
            long long rightChildren = (childNum == suffix.size() - 1) ? 0 : suffix[childNum + 1];

            dp[src][1] = max(dp[src][1], 1 + leftChildren + rightChildren + dp[child][0]);
            childNum++;
        }
    }

    static long long maximumEdges(long long numNodes,vector<vector<long long>> edges) {
        vector<vector<long long>> adj(numNodes+1);

        for(vector<long long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<long long>> dp(numNodes+1,vector<long long>(2));
        solver(adj,1,0,dp);
        return max(dp[1][0],dp[1][1]);
    }
};



