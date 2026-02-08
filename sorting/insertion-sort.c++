#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        int j = i - 1;
        int current = arr[i];
        while(j >=0 && arr[j] > current){
              arr[j + 1] = arr[j];
              j--;
            }
        arr[j + 1] = current;
    }
}
int main(){
    vector<int> arr = {1, 5, 3, 0, 12, 4};

    insertionSort(arr);
    for(int i : arr){
        cout << i << " ";
    }
}