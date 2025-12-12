#include <bits/stdc++.h>
using namespace std ;


void addedge(vector <int> list[],int src, int des,int *c ){
    list[src].push_back(des);
    list[des].push_back(src);
    c[src]++;
    c[des]++;
}

void del(vector <int> list[],int * c,int src , int des){
    int j=0;
    int z=1;
    for( int i : list[src]){
        if(i==des) {
            z=0;
            break;
        }
        j++;
    }
    if(z) {
        // cout<< "-1" << endl;
        return ;
    }
    list[src].erase(list[src].begin()+ j);
    j=0;
    for( int i : list[des]){
        if(i==src) break;
        j++;
    }
    list[des].erase(list[des].begin()+ j);
    c[des]--;
    c[src]--;

}

void dfs ( vector <int> list[],int * c,int k,int v){
    bool visited[v+1]={0};
    vector <int> p;
    visited[k]=true;
    queue <int> q;
    q.push(k);
    while(!q.empty()){
        int no;
        no = q.front();
        q.pop();
        p.push_back(no);
        for(int s : list[no]){
            if(!visited[s]){
                visited[s]=true ;
                q.push(s);
            }
        }
    }
    sort(p.begin(),p.end());
    for ( int i: p){
        cout << i<< " ";
    }
    cout << endl;
}

int main(){
    int n;
    int q;
    cin >> n;
    vector <int> list[n+1];
    cin >> q;
    int c[n+1]={0};
    for(int i=0;i<q;i++){
        // char t[20];
        // scanf("%s",t);
        // printf("%s",t);
        int src,des;
        cin >> src >> des;
        addedge(list,src,des,c);
    }
    int o;
    cin >> o;
    for(int i=0;i<o;i++){
        int k;
        cin >> k;
        dfs(list,c,k,n);
    }

}
