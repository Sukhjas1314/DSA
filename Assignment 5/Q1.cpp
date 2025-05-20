#include<iostream>
using namespace std;

#define V 5
int graph[V][V] = {
    {0,1,0,1,0},
    {1,0,1,1,1},
    {0,1,0,0,1},
    {1,1,0,0,1},
    {0,1,1,1,0}
};

int path[V];

bool check(int v,int pos){
    if (graph[path[pos - 1]][v] == 0){
        return false;
    }
    for (int i = 0 ; i < pos ; i++){
        if (path[i] == v){
            return false;
        }
    }
    return true;
}

bool hamcycleutil(int pos){
    if (pos == V){
        return graph[path[pos - 1]][path[0]] == 1;
    }
    for (int v = 1 ; v < V ; v++){
        if (check(v,pos)){
            path[pos] = v;
            if (hamcycleutil(pos + 1)){
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

bool hamcycle(){
    for (int i = 0 ; i < V ; i++){
        path[i] = -1;
    }
    path[0] = 0;
    if(!hamcycleutil(1)){
        cout << "No hamiltonian cycle exists" << endl;
        return false;
    }
    cout << "Hamiltonian cycle exists : ";
    for (int i = 0 ; i < V ; i++){
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
    return true;
}

int main(){
    cout << endl;
    hamcycle();
    cout << endl;
    return 0;

}