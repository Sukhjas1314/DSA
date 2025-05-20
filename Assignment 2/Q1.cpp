#include<iostream>
using namespace std;
struct Activity{
    int start,finish;
};

bool compare(Activity a,Activity b){
    return a.finish < b.finish;
}

void activitySelection(int start[],int finish[],int n){
    vector<Activity> activities(n);

    for (int i = 0 ; i < n ; i++){
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    sort(activities.begin(),activities.end(),compare);

    int count = 1;
    cout << "The activities possible are : " << endl;
    cout << "(" << activities[0].start << "," << activities[0].finish << ")" << endl;
    int lastfinish = activities[0].finish;

    for (int i = 0 ; i < n ; i++){
        if(activities[i].start >= lastfinish){
            cout << "(" << activities[i].start << "," << activities[i].finish << ")";
            cout << endl;
            lastfinish = activities[i].finish;
            count++;
        }
    }
    cout << "Maximum number of activities possible are : " << count << endl;
}

int main(){
    int start[] = {1,3,0,5,8,5};
    int finish[] = {2,4,6,7,9,9};
    int n = sizeof(start)/sizeof(int);
    activitySelection(start,finish,n);
    return 0;
}