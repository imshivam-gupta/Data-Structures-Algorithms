#include <bits/stdc++.h>
using namespace std;

class LCA {
public:
    vector<int> path1, path2;

    bool findPath(int current, int target, vector<int>& path, int parent,vector<vector<int>> &tree) {
        path.push_back(current);

        if (current == target) return true;

        for (int neighbor : tree[current]) {
            if (neighbor != parent) {
                if (findPath(neighbor, target, path, current,tree)) return true;
            }
        }

        path.pop_back();
        return false;
    }

    int findLCA(int u, int v,vector<vector<int>> &tree) {
        if (!findPath(1, u, path1, -1,tree) || !findPath(1, v, path2, -1,tree)) {
            return -1;
        }

        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) break;
        }

        return path1[i-1];
    }
};

class LCABinaryLift {
public:

    void dfs(int node, int par, vector<vector<int>> &tree,vector<vector<int>> &dp,vector<int> &level,int l=0) {
        dp[node][0] = par;

        for(int i=1;i<=16;i++) {
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }

        level[node] = l;
        for(int itr:tree[node]) {
            if(itr!=par) {
                dfs(itr,node,tree,dp,level,l+1);
            }
        }
    }

    int getKthPar(int node,int k,vector<vector<int>> &dp) {
        for(int i=16;i>=0;i--) {
            if((k>>i)&1) {
                node = dp[node][i];
            }
        }

        return node;
    }

    void findLCA(int u, int v,vector<vector<int>> &tree.int n) {
        vector<vector<int>> dp(n+1,vector<int>(17,0));
        vector<int> level(n+1,0);
        dfs(1,0,tree,dp,level);

        int q; cin >> q;
        while(q--) {
            int a,b; cin >> a >> b;
            if(level[a]>level[b]) {
                swap(a,b);
            }

            int k = level[b] - level[a];
            b = getKthPar(b,k,dp);

            if(a==b) {
                return a;
            }

            for(int i=16;i>=0;i--) {
                if(dp[a][i]!=dp[b][i]) {
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }

            cout << dp[a][0] << endl;
        }
    }
};



int main() {
    int n;cin >> n;

    vector<vector<int>> tree;
    tree.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int u, v;
    cin >> u >> v;

    LCA l;
    int lca = l.findLCA(u, v,tree);
    if (lca != -1) {
        cout << "LCA of " << u << " and " << v << " is " << lca << endl;
    } else {
        cout << "LCA does not exist" << endl;
    }

    return 0;
}
