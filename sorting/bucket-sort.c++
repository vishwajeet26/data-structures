#include <iostream>
#include <vector>
using namespace std;


void insertionSort(vector<float>& arr){
    for(int i = 1; i < arr.size(); i++){
        int j = i - 1;
        float current = arr[i];
        while(j >= 0 && arr[i] < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void bucketSort(vector<float>& arr){
    int n = arr.size();
    vector<float> res[n];

    //bucket formation
    for(int i = 0; i < arr.size(); i++){
        int idx = n * arr[i];
        res[idx].push_back(arr[i]);
    }

    //sort inside each bucket
    for(int i = 0; i < n; i++){
        insertionSort(res[i]);
    }

    // concatenate
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < res[i].size(); j++){
            arr[idx++] = res[i][j];
         }
    }

}

int main(){
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    bucketSort(arr);
    for(float i : arr){
        cout << i << " ";
    }
}