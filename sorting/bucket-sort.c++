#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<int>& arr){

}

int main(){
    vector<int> arr = {1, 5, 3, 0, 12, 4};

    bucketSort(arr);
    for(int i : arr){
        cout << i << " ";
    }
}