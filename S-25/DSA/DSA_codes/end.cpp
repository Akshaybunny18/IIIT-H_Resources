#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    priority_queue <pair<int,int>> pq;
    vector <int> dist(n,INT_MIN);
    pq.push({0,0});



}