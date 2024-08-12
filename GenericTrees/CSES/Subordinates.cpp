#include<bits/stdc++.h>
using namespace std;

class Subordinates {
public:

    static void solver(int src,int par,vector<vector<int>> &adj,vector<int> &ans) {
        int subords = 0;

        for(int child:adj[src]) {
            if(child!=par) {
                solver(child,src,adj,ans);
                subords += (1+ans[child]);
            }
        }

        ans[src] = subords;
    }

    static vector<int> findSubordinates(int numOfEmployees, vector<int> bosses) {
        vector<vector<int>> adj(numOfEmployees+1);

        for(int i=2;i<=numOfEmployees;i++) {
            adj[bosses[i-2]].push_back(i);
        }

        vector<int> ans(numOfEmployees+1);
        solver(1,0,adj,ans);
        return ans;
    }
};