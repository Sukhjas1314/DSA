#include<iostream>
using namespace std;
class heap{
    public :
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index / 2;
                if(arr[parent] < arr[index]){
                    swap(arr[index],arr[parent]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i = 1 ; i <= size ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void deletefromHeap(){
            if(size == 0){
                cout << "Nothing can be deleted" << endl;
                return;
            }
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size){
                int left = 2 * i;
                int right = 2 * i + 1;

                if(left <= size && arr[i] < arr[left]){
                    swap(arr[i],arr[left]);
                    i = left;
                }
                else if(right <= size && arr[i] < arr[right]){
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else{
                    return;
                }
            }
        }
};
void heapify(int arr[],int n,int i){
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
    h.print();

    int arr[6] = {-1,53,54,55,50,52};
    int n = 5;
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr,n,i);
    }
    cout << "Printing the array : ";
    for(int i = 1 ; i <= n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    cout << endl;
    return 0;
}