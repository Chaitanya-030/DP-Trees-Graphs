#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200001];

void solve(int node, int par, vector<int>& ans) {
    int subords = 0;
    for(auto  child : adj[node]) {
        if(child != par) {
            solve(child, node, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[node] = subords;
}

int main() {

    int n; cin>>n;
    vector<int> ans(n+1);
    for(int i=2;i<=n;i++) {
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    solve(1, 0, ans);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}