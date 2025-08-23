#include <iostream>
#include <vector>
#include "sorting/mergeSort.hpp"
#include <chrono>
using namespace std;
int main(int argc, char *argv[]){

    const int SIZE = 20;
    vector<int>nums(SIZE);

    for(int i=0;i<SIZE;i++){
        nums[i]=rand()%1000;
    }
    for(int i=0;i<SIZE;i++){
        cout<<nums[i]<<" ";
    }
    MergeSort *mergesort= new MergeSort(&nums);

    auto start = chrono::high_resolution_clock::now();
    mergesort->sort();
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<nums[i]<<" ";
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeSortDuration = end-start;
    cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" << std::endl;
    delete mergesort;
}