#include<iostream>
using namespace std;

class Knapsack{
    public :
        int profit;
        int weight;

        Knapsack(int profit,int weight){
            this->profit = profit;
            this->weight = weight;
        }
};

bool compare(Knapsack a,Knapsack b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1 > r2;
}

int main(){
    int n = 3;
    Knapsack bag[] = {
        Knapsack(60,10),
        Knapsack(100,20),
        Knapsack(120,30),
    };

    int w = 50;

    sort(bag,bag + n,compare);
    
    double tprofit = 0;

    for (int i = 0 ; i < n ; i++){
        if(w >= bag[i].weight){
            w -= bag[i].weight;
            tprofit += bag[i].profit;
        }
        else{
            tprofit += bag[i].profit * ((double)w/bag[i].weight);
            break;
        }
    }
    cout << "Maximum profit : " << tprofit << endl;
    return 0;
}