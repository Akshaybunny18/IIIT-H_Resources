#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue <int> q[2] ;
            int n = grid.size() ;
            int m = grid[0].size() ;
            int fresh = 0 ;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(grid[i][j] == 2){
                        q[0].push(i) ;
                        q[0].push(j) ;
                    }
                    else if(grid[i][j] == 1){
                        fresh++ ;
                    }
                }
            }
            if(fresh == 0) return 0 ;
            int time = 0 ;
            while(!q[0].empty()){
                while(!q[0].empty()){
                    int x = q[0].front() ;
                    q[0].pop() ;
                    int y = q[0].front() ;
                    q[0].pop() ;
                    if(x-1 >= 0 && grid[x-1][y] == 1){
                        grid[x-1][y] = 2 ;
                        q[1].push(x-1) ;
                        q[1].push(y) ;
                        fresh-- ;
                    }
                    if(x+1 < n && grid[x+1][y] == 1){
                        grid[x+1][y] = 2 ;
                        q[1].push(x+1) ;
                        q[1].push(y) ;
                        fresh-- ;
                    }
                    if(y-1 >= 0 && grid[x][y-1] == 1){
                        grid[x][y-1] = 2 ;
                        q[1].push(x) ;
                        q[1].push(y-1) ;
                        fresh-- ;
                    }
                    if(y+1 < m && grid[x][y+1] == 1){
                        grid[x][y+1] = 2 ;
                        q[1].push(x) ;
                        q[1].push(y+1) ;
                        fresh-- ;
                    }

                }
                time++ ;
                swap(q[0],q[1]) ;
            }
            if(fresh == 0) return time ;
            return -1 ;
        } 
    };