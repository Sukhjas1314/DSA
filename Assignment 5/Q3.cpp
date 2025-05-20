#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs1(int u,vector<vector<int> > &adj,vector<bool> &visited,stack<int> &st){
    visited[u] = true;
    for (int j = 0 ; j < adj[u].size() ; j++){
        int v = adj[u][j];
        if (!visited[v]){
            dfs1(v,adj,visited,st);
        }
    }
    st.push(u);
}

void dfs2(int u,vector<vector<int> > &transpose,vector<bool> &visited){
    visited[u] = true;
    for(int j = 0 ; j < transpose[u].size() ; j++){
        int v = transpose[u][j];
        if(!visited[v]){
            dfs2(v,transpose,visited);
        }
    }
}

int kosaraju(int V,vector<vector<int> >&adj){
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i = 0 ; i < V ; i++){
        if (!visited[i]){
            dfs1(i,adj,visited,st);
        }
    }
    vector<vector<int> > transpose(V);
    for (int i = 0 ; i < V ; i++){
        for (int j = 0 ; j < adj[i].size() ; j++){
            int v = adj[i][j];
            transpose[v].push_back(i);
        }
    }
    for(int i = 0 ; i < V ; i++){
        visited[i] = false;
    }
    int sccCount = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if (!visited[u]){
            dfs2(u,transpose,visited);
            sccCount++;
        }
    }
    return sccCount;
}

int main(){
    int V = 5;
    vector<vector<int> > adj(V);
    adj[0].push_back(3);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[2].push_back(1);
    adj[3].push_back(4);

    int kosa = kosaraju(V,adj);
    cout << endl << "Number of strongly connected components : " << kosa << endl << endl;
    return 0;
}