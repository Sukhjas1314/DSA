#include<iostream>
using namespace std;

class Job{
    public :
        char id;
        int deadline;
        int profit;

        Job(char id,int deadline,int profit){
            this->id = id;
            this->deadline = deadline;
            this->profit = profit;
        }
};

bool compare(Job a,Job b){
    return a.profit > b.profit;
}

int main(){
    Job jobs[] = {
        Job('a',4,20),
        Job('b',1,10),
        Job('c',1,40),
        Job('d',1,30)
    };

    int n = sizeof(jobs)/sizeof(jobs[0]);

    sort(jobs,jobs + n,compare);

    int max_deadline = 0;
    for (int i = 0 ; i < n ; i++){
        if(jobs[i].deadline > max_deadline){
            max_deadline = jobs[i].deadline;
        }
    }

    bool slot[max_deadline + 1];
    for (int i = 0 ; i <= max_deadline ; i++){
        slot[i] = false;
    }

    int tprofit = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = jobs[i].deadline ; j >= 1 ; j--){
            if(!slot[j]){
                slot[j] = true;
                tprofit += jobs[i].profit;
                cout << "Scheduled Jobs : " << jobs[i].id << " at time : " << j << endl;
                break;
            }
        }
    }
    cout << "Total profit : " << tprofit << endl;
    return 0;
}