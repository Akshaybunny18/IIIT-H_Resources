#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    vector <long long > d;
    for(int hhh=0;hhh<t;hhh++){
        int n,m;
        cin>>n>>m;
        int** arr = (int**) malloc(sizeof(int*) * n);
        queue <int> q;
        int ** visited = (int**) malloc(sizeof(int*) * n);
        for(int i=0;i<n;i++){
            arr[i] = (int*) malloc(sizeof(int) * m);
            visited[i] = (int*) malloc(sizeof(int) * m);
            for(int j=0;j<m;j++){
                int k;
                cin>>k;
                arr[i][j]=k;
                visited[i][j]=0;
                if(k){
                    q.push(i);
                    q.push(j);
                }
            }
        }
        long long sum=0;
        long long max=0;
        while(!q.empty()){
            queue <int> qq;
            int ii=q.front();
            q.pop();
            int jj=q.front();
            q.pop();
            // cout<<arr[ii][jj];
            if(!visited[ii][jj]){
                // cout<<"hi";
                qq.push(ii);
                qq.push(jj);
            }
            sum=0;
            while(!qq.empty()){
                // cout<<"hi";
                int i=qq.front();
                qq.pop();
                int j=qq.front();
                qq.pop();
                sum+=arr[i][j];
                // cout<<arr[i][j];
                visited[i][j]=1;
                if (i + 1 < n && arr[i + 1][j]) {
                    // add_edge(i * m + j, (i + 1) * m + j);
                    if(!visited[i+1][j]){
                        visited[i+1][j]=1;
                        qq.push(i+1);
                        qq.push(j);
                        // cout<<arr[i+1][j];
                    }
                }
                if (i - 1 >= 0 && arr[i - 1][j]) {
                    // add_edge(i * m + j, (i - 1) * m + j);
                    if(!visited[i-1][j]){
                        visited[i-1][j]=1;
                        qq.push(i-1);
                        qq.push(j);
                    }
                    // cout<<visited[0][1];
                }
                if (j + 1 < m && arr[i][j + 1]) {
                    // add_edge(i * m + j, i * m + (j + 1));
                    if(!visited[i][j+1]){
                        visited[i][j+1]=1;
                        qq.push(i);
                        // cout<<arr[i][j+1];
                        qq.push(j+1);
                    }
                }
                if (j - 1 >= 0 && arr[i][j - 1]) {
                    // add_edge(i * m + j, i * m + (j - 1));
                    if(!visited[i][j-1]){
                        visited[i][j-1]=1;
                        qq.push(i);
                        qq.push(j-1);
                    }
                }
            }
            if(sum>max) max=sum;
        }
        // if(max==-100000000000000) {
        //     cout<<"0"<<endl;
        //     continue;
        // }
        cout<<max<<endl;
        // d.push_back(max);
    }
    for(long long int ji:d){
        // cout<<ji<<endl;
    }
}