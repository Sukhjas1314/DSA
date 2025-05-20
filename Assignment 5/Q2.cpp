#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Topological (Using Kahn's)
void TopoKahn(int V,vector<vector<int> > &adj){
    vector<int> indegree(V,0);

    for (int i = 0 ; i < V ; i++){
        for (int j = 0 ; i < adj[i].size() ; i++){
            int x = adj[i][j];
            indegree[x]++;
        }
    }
    queue<int> q;
    for (int i = 0 ; i < V ; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0){
                q.push(v);
            }
        }
    }
    cout << "Topological order according to Kahn's algorithm : ";
    for (int i = topo.size() - 1 ; i >= 0 ; i--){
        cout << topo[i] << " ";
    }
    cout << endl;
}

// Topological (Using DFS)
void dfs(int u,vector<bool> &visited,vector<vector<int> > &adj,vector<int> &topo){
    visited[u] = true;
    for(int j = 0 ; j < adj[u].size() ; j++){
        int v = adj[u][j];
        if (!visited[v]){
            dfs(v,visited,adj,topo);
        }
    }
    topo.push_back(u);
}
void dfsTopo(int V,vector<vector<int> > &adj){
    vector<bool> visited(V,false);
    vector<int> topo;

    for (int i = 0 ; i < V ; i++){
        if (!visited[i]){
            dfs(i,visited,adj,topo);
        }
    }
    cout << "Topological order using DFS : ";
    for (int i = topo.size() - 1 ; i >= 0 ; i--){
        cout << topo[i] << " ";
    }
    cout << endl;
}

int main(){
    int V = 6;
    vector<vector<int> > adj(V);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    TopoKahn(V,adj);
    dfsTopo(V,adj);

    return 0;
}