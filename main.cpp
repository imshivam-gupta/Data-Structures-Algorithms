#include <bits/stdc++.h>

#include "DynamicProgramming/CSES/CoinCombinationsI.cpp"
#include "GenericTrees/CSES/Subordinates.cpp"
#include "GenericTrees/CSES/TreeMatching.cpp"
#include "GenericTrees/CSES/TreeDiameter.cpp"
#include "GenericTrees/CSES/TreeDistanceI.cpp"
#include "GenericTrees/CSES/TreeDistanceII.cpp"
#include "Graphs/Learning/BFS.cpp"
#include "DynamicProgramming/CSES/RemovingDigits.cpp"
#include "DynamicProgramming/CSES/CoinCombinationsII.cpp"
#include "DynamicProgramming/CSES/DiceCombinations.cpp"
#include "DynamicProgramming/CSES/MinimizingCoins.cpp"
#include "DynamicProgramming/CSES/GridPaths.cpp"
#include "DynamicProgramming/CSES/BookShop.cpp"
#include "Adhoc/SpecialSubset.cpp"
using namespace std;

int main() {

    // Problem 1: Dice Combinations(https://cses.fi/problemset/task/1633)
    // int desiredSum; cin >> desiredSum;
    // cout << DiceCombinations::countWays(desiredSum) << endl;

    // Problem 2: Minimizing Coins(https://cses.fi/problemset/task/1634)
    // int desiredSum, numCoins; cin >> numCoins >> desiredSum;
    // vector<int> coins(numCoins);
    // for (int i = 0; i < numCoins; ++i) {
    //     cin >> coins[i];
    // }
    //
    // cout << MinimizingCoins::minimumCoins(desiredSum, coins) << endl;


    // Problem 3: Coin Combinations I(https://cses.fi/problemset/task/1635)
    // int numCoins, desiredSum; cin >> numCoins >> desiredSum;
    // vector<int> coins(numCoins);
    // for (int i = 0; i < numCoins; ++i) {
    //     cin >> coins[i];
    // }
    //
    // cout << CoinCombinationsI::distinctWays(desiredSum, coins) << endl;

    // Problem 4: Coin Combinations II(https://cses.fi/problemset/task/1636)
    // int numCoins, desiredSum; cin >> numCoins >> desiredSum;
    // vector<int> coins(numCoins);
    // for (int i = 0; i < numCoins; ++i) {
    //     cin >> coins[i];
    // }
    //
    // cout << CoinCombinationsII::distinctWays(desiredSum, coins) << endl;


    // Adhoc Special Subsets
    // int n; cin >> n;
    // vector<int> arr(n);
    // for(int &x:arr) cin >> x;
    // int target; cin >> target;
    // cout << SpecialSubsets::countSubsets(arr,target) << endl;

    // Problem 6: Removing Digits(https://cses.fi/problemset/task/1637)
    // int input; cin >> input;
    // cout << RemovingDigits::countSteps(input) << endl;

    // Problem 7: Grid Paths(https://cses.fi/problemset/task/1638)
    // int n; cin >>n;
    // vector<string> grid(n);
    // for(string &x:grid) cin >> x;
    // cout << GridPaths::countPaths(grid) << endl;

    // Problem 8: Book Shop(https://cses.fi/problemset/task/1158)
    // int n,maxPrice; cin >>n >> maxPrice;
    // vector<int> price(n);
    // for(int &x:price) cin >> x;
    //
    // vector<int> pages(n);
    // for(int &x:pages) cin >> x;
    // cout << BookShop::maximumPages(price,pages,maxPrice);

    // Problem 9: Array Description(https://cses.fi/problemset/task/1746)
    // dp[m][m][m]

    // Learning Graphs
    // int n, m;
    // cin >> n >> m;
    //
    // Graph g(n, m);
    //
    // for(int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v);  // Use the dot operator to call member functions
    // }
    //
    // g.visualiseGraph();

    // BFS
    // int n, m;
    // cin >> n >> m;
    // Graph g(n, m);
    // for(int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v);
    // }
    //
    // g.visualiseGraph();
    //
    // vector<int> bfsResult = g.bfsOfGraph(n);
    // cout << "BFS Traversal of the Graph:" << endl;
    // for(int i : bfsResult) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // Trees Problem 1
    // int n; cin >> n;
    // vector<int> bosses(n-1);
    // for(int i=0;i<n-1;i++) {
    //     cin >> bosses[i];
    // }
    //
    // vector<int> ans = Subordinates::findSubordinates(n,bosses);
    // for(int i=1;i<ans.size();i++) {
    //     cout << ans[i] << endl;
    // }

    // Trees Problem 2
    // int n; cin >> n;
    // vector<vector<int>> edges;
    // for(int i=1;i<n;i++) {
    //     int u,v; cin >> u >>v;
    //     edges.push_back({u,v});
    // }
    // cout << TreeMatching::maximumEdges(n,edges) << endl;

    // // Trees Problem 3
    // int n; cin >> n;
    // vector<vector<long long>> edges;
    // for(int i=1;i<n;i++) {
    //     int u,v; cin >> u >>v;
    //     edges.push_back({u,v});
    // }
    // cout << TreeDiameter::diameter(n,edges) << endl;

    // Trees Problem 4
    // int n; cin >> n;
    // vector<vector<long>> edges;
    // for(int i=1;i<n;i++) {
    //     int u,v; cin >> u >>v;
    //     edges.push_back({u,v});
    // }
    // vector<long> ans = TreeDistanceI::maxDistance(n,edges);
    // for(int i=1;i<ans.size();i++) {
    //     cout << ans[i] << " ";
    // }

    // Trees Problem 5
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



    return 0;
}
