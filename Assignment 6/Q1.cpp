#include<iostream>
#include<climits>
#include<queue>
#include<cstring>
using namespace std;

#define V 6

bool bfs(int rgraph[V][V],int s,int t,int parent[]){
    bool visited[V];
    memset(visited,false,sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int v = 0 ; v < V ; v++){
            if (!visited[v] && rgraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int graph[V][V],int s,int t){
    int u,v;
    int rgraph[V][V];

    for (u = 0 ; u < V ; u++){
        for (v = 0 ; v < V ; v++){
            rgraph[u][v] = graph[u][v];
        }
    }
    int parent[V];
    int max_flow = 0;

    while (bfs(rgraph,s,t,parent)){
        int path_flow = INT_MAX;
        for (v = t ; v != s ; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }

        for (v = t ; v != s ; v = parent[v]){
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow; 
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main(){
    int graph[V][V] = {
        {0,16,13,0,0,0},
        {0,0,10,12,0,0},
        {0,4,0,0,14,0},
        {0,0,9,0,0,20},
        {0,0,0,7,0,4},
        {0,0,0,0,0,0}
    };

    int source = 0;
    int sink = 5;

    cout << "The maximum flow possible : " << fordFulkerson(graph,source,sink) << endl;

    return 0;
}