#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          // Code here
            vector <int> result ;
            queue <int> q ;
            vector <bool> visited (adj.size(),false) ;
            q.push(0) ;
            visited[0] = true ;
            while(!q.empty()){
                int node = q.front() ;
                q.pop() ;
                result.push_back(node) ;
                for(int it : adj[node]){
                    if(!visited[it]){
                        q.push(it) ;
                        visited[it] = true ;
                    }
                }
            }
            return result ;
      }
  };


  class Solutio {
    public:
        // Function to return a list containing the DFS traversal of the graph.
        vector<int> dfsOfGraph(vector<vector<int>>& adj) {
            // Code here
            vector <int > v;
            v = dfs(0,adj,v) ;
            return v ;
            
        }
        vector <int> dfs(int node,vector<vector<int>>& adj,vector<int>& v){
            v.push_back(node) ;
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(find(v.begin(),v.end(),adj[node][i]) == v.end()){ // what does find function returns if element is not found
                    // if element is not found then it returns the end of the vector
                    // if element is found then it returns the iterator pointing to that element
                    v = dfs(adj[node][i],adj,v) ;
                }
            }
            return v ;
        }
            
  };
  
  
