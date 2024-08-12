#include<bits/stdc++.h>
using namespace std;

class TreeDistanceI {
public:

    static void depthHelper(long src,long par,vector<vector<long>> &adj,vector<long> &depth) {
        depth[src] =0;

        for(long child:adj[src]) {
            if(child!=par) {
                depthHelper(child,src,adj,depth);
                depth[src] = max(depth[src], 1+depth[child]);
            }
        }
    }

    static void solver(long src,long par,long parAns, vector<vector<long>> &adj,vector<long> &ans, vector<long> &depth) {

        vector<long> prefixMax, suffixMax;
        for(long child: adj[src]) {
            if(child!=par) {
                prefixMax.push_back(depth[child]);
                suffixMax.push_back(depth[child]);
            }
        }

        for(long i=1;i<prefixMax.size();i++) {
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
        }

        for(long i=suffixMax.size()-2;i>=0;i--) {
            suffixMax[i] = max(suffixMax[i],suffixMax[i+1]);
        }

        int childNum =0;
        for(long child:adj[src]) {
            if(child!=par) {
                long opt1 = (childNum==0)? INT_MIN: prefixMax[childNum-1];
                long opt2 = (childNum==suffixMax.size()-1)? INT_MIN: suffixMax[childNum+1];
                long partialAns = 1 + max({parAns,opt1,opt2});

                solver(child,src,partialAns,adj,ans,depth);
                childNum++;
            }
        }

        ans[src] = 1+ max(parAns, (prefixMax.empty()?-1:prefixMax.back()));
    }

    static vector<long> maxDistance(long numNodes,vector<vector<long>> &edges) {
        vector<vector<long>> adj(numNodes+1);

        for(vector<long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long> depth(numNodes+1);
        depthHelper(1,0,adj,depth);

        vector<long> ans(numNodes+1);
        solver(1,0,-1, adj,ans,depth);
        return ans;
    }
};