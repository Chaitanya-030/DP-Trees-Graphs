#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public : 
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findupar(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findupar(parent[node]);
        }

        void unionbyrank(int u, int v) {
            int ultp_u = findupar(u);
            int ultp_v = findupar(v);
            if(ultp_u == ultp_v) return;
            if(rank[ultp_u] < rank[ultp_v]) {
                parent[ultp_u] = ultp_v;
            }
            else if(rank[ultp_u] > rank[ultp_v]) {
                parent[ultp_v] = ultp_u;
            }
            else {
                parent[ultp_v] = ultp_u;
                rank[ultp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findupar(u); 
            int ulp_v = findupar(v); 
            if(ulp_u == ulp_v) return; 
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
    }

};

int main() {
    DisjointSet ds(7);
    ds.unionbyrank(1, 2);
    ds.unionbyrank(2, 3);
    ds.unionbyrank(4, 5);
    ds.unionbyrank(6, 7);
    ds.unionbyrank(5, 6);

    if(ds.findupar(3) == ds.findupar(7)) {
        cout<<"Same component"<<endl;
    }
    else {
        cout<<"Not Same component"<<endl;
    }

    ds.unionbyrank(3, 7);

    if(ds.findupar(3) == ds.findupar(7)) {
        cout<<"Same component"<<endl;
    }
    else {
        cout<<"Not Same component"<<endl;
    }

    return 0;
}