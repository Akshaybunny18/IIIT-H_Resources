#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int** arr,int start,vector<bool>&visited){
    int v=n;
    queue <int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // cout<<node<<" ";
        for(int ne=0;ne<n;ne++){
            if(!visited[ne] && arr[node][ne]){
                visited[ne]=true;
                q.push(ne);
            }
        }
    }
    // cout<<endl;
}


int main(){
    int m;
    cin>>n>>m;
    int** arr = (int**) malloc(sizeof(int*) * n);
    
    for(int i=0;i<n;i++){
        arr[i] = (int*) malloc(sizeof(int) * n);
        for(int j=0;j<n;j++){
            int q;
            cin>>q;
            arr[i][j]=q;
        }
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        // cout<<"gyukjh";
        vector<bool> visited(n,false);
        dfs(arr,x,visited);
        // cout<< endl;
        if(visited[y]){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    
}