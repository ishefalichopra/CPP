#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool dfs(int node, int parent, vector<bool>& visited, vector<set<int>>& graph){
    visited[node] = true;
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            if(!dfs(neighbor, node, visited, graph)){
                return false;
            }
        } else if(neighbor != parent){
            return false; // Found a cycle
        }
    }
    return true;
}

int isTree(int n, int m, vector<vector<int>>& edges){
    if(m != n-1) return 0;

    vector<set<int>> adj(n);

    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];

        if(u == v) return 0; // Self loop
        if(adj[u].count(v)) return 0; // multiple edge
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(n, false);
    if(!dfs(0, -1, visited, adj)) return 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]) return 0; // Not all nodes are visited
    }
    return 1; // It's a tree
}

int main()
{
    int n = 5, m = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    cout << isTree(n, m, edges) << endl; // Output: 1 (It's a tree)
    return 0;
}