#include<bits/stdc++.h>
using namespace std;
int dp[200001][2];

int solve(int node, int inc, vector<vector<int>>& adj, int par) {
    if(dp[node][inc] != -1) return dp[node][inc];

    if(inc) {
        int ans = 0;
        for(auto it : adj[node]) {
            if(it != par) {
                ans += solve(it, 1, adj, node);
            }
        }
        int f_ans = 0;
        for(auto it : adj[node]) {
            if(it != par) {
                f_ans = max(f_ans, ans - dp[it][1] + 1 + solve(it, 0, adj, node));
            }
        }
        dp[node][inc] = f_ans;
        return f_ans;
    }
    else {
        int ans = 0;
        for(auto it : adj[node]) {
            if(it != par) {
                ans += solve(it, 1, adj, node);
            }
        }
        dp[node][inc] = ans;
        return ans;
    }
}
int main() {
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n-1;i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = max(solve(1, 0, adj, -1), solve(1, 1, adj, -1));
    cout<<ans<<endl;

    return 0;
}