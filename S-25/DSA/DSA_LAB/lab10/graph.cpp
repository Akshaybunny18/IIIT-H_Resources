#include <bits/stdc++.h>
using namespace std ;


void addedge(vector <int> list[],int src, int des,int *c ){
    int j=0;
    int z=1;
    for( int i : list[src]){
        if(i==des) {
            z=0;
            break;
        }
        j++;
    }
    if(!z) {
        // cout<< "-1" << endl;
        return ;
    }
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
        cout<< "-1" << endl;
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



int main(){
    int n;
    int q;
    cin >> n;
    vector <int> list[n];
    cin >> q;
    int c[n]={0};
    for(int i=0;i<q;i++){
        char t[20];
        scanf("%s",t);
        // printf("%s",t);
        if(t[0]=='I'){
            int src,des;
            cin >> src >> des;
            addedge(list,src,des,c);
        }
        else if(t[0]=='D'){
            int src,des;
            cin >> src >> des;
            del(list,c,src,des);
        }
        else if(t[0]=='N'){
            int u;
            cin >> u;
            int k = c[u]<0?0:c[u];
            cout << k << endl;
        }
    }


}
