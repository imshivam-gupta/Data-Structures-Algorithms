#include<bits/stdc++.h>
using namespace std;

class TreeDistanceII {
public:

    static void helper(long src,long par,vector<vector<long>> &adj,vector<long> &subtreeSize,vector<long> &subtreeAns) {
        long numOfNodes = 1;
        long ansForSubtree =0;

        for(long child: adj[src]) {
            if(child!=par) {
                helper(child,src,adj,subtreeSize,subtreeAns);
                numOfNodes += subtreeSize[child];
                ansForSubtree += subtreeSize[child] + subtreeAns[child];
            }
        }

        subtreeSize[src] = numOfNodes;
        subtreeAns[src] = ansForSubtree;
    }

    static void solver(long src,long par,long parAns, vector<vector<long>> &adj,vector<long> &ans, vector<long> &subtreeSize, vector<long> &subtreeAns,long& numNodes) {
        ans[src] = subtreeAns[src] + (parAns+numNodes-subtreeSize[src]);
        for(long child:adj[src]) {
            if(child!=par) {
                solver(child,src,ans[src]-subtreeAns[child]-subtreeSize[child],adj,ans,subtreeSize,subtreeAns,numNodes);
            }
        }
    }

    static vector<long> sumDistance(long numNodes,vector<vector<long>> &edges) {
        vector<vector<long>> adj(numNodes+1);

        for(vector<long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long> subtreeSize(numNodes+1);
        vector<long> subTreeAns(numNodes+1);
        helper(1,0,adj,subtreeSize,subTreeAns);

        vector<long> ans(numNodes+1);
        solver(1,0,0, adj,ans,subtreeSize,subTreeAns,numNodes);
        return ans;
    }
};

int main(){
    int n; cin >> n;
    vector<vector<long>> edges;
    for(int i=1;i<n;i++) {
        int u,v; cin >> u >>v;
        edges.push_back({u,v});
    }
    vector<long> ans = TreeDistanceII::sumDistance(n,edges);
    for(int i=1;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}