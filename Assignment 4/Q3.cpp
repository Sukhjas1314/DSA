#include<iostream>
using namespace std;
const int V = 4;

bool check(int graph[V][V],int color[],int v,int c){
    for(int i = 0 ; i < V ; i++){
        if (graph[v][i] && color[i] == c){
            return false;
        }
    }
    return true;
}

bool graphcolorutil(int graph[V][V],int m,int color[],int v){
    if (v == V){
        return true;
    }
    for (int c = 1 ; c <= m ; c++){
        if (check(graph,color,v,c)){
            color[v] = c;
            if (graphcolorutil(graph,m,color,v + 1)){
                return true;
            }
            color[v] = 0;  // backtrack
        }
    }
    return false;
}

bool graphcolor(int graph[V][V],int m){
    int color[V] = {0};

    if (!graphcolorutil(graph,m,color,0)){
        cout << "Solution doesn't exists" << endl;
        return false;
    }
    cout << "Solution exists : " << endl;
    for (int i = 0 ; i < V ; i++){
        cout << color[i] << " ";
    }
    cout << endl;
    return true;
}

int main(){
    int g1[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m1 = 3;
    graphcolor(g1,m1);

    int g2[V][V] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    int m2 = 3f;
    graphcolor(g2,m2);

    return 0;
}