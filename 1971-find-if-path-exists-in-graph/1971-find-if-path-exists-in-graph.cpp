class Solution {
public:
void dfs(int node, unordered_map<int,vector<int>>&graph,vector<int>&visited){
    visited[node]=1;
    for(int nbr:graph[node]){
        if(!visited[nbr]){
            dfs(nbr,graph,visited);
        }
    }
}
 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         unordered_map<int ,vector<int>>graph;
         for(int i=0;i<edges.size();i++){
           int a=edges[i][0];
           int b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
         }
         vector<int>visited(n+1);
         dfs(source,graph,visited);
         if(!visited[destination]){
            return false;
         }
         return true;
         
    }
};