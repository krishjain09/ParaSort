#include <iostream>
#include <vector>
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"
#include <chrono>
using namespace std;
int main(int argc, char *argv[]){

    const int SIZE = 10000000;
    vector<int>nums(SIZE);
    vector<int>nums1(SIZE);
    for(int i=0;i<SIZE;i++){
        nums[i]=rand()%10000000;
        nums1[i]=rand()%10000000;
    }
    
    MergeSort *mergesort= new MergeSort(&nums);
    auto start = chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeSortDuration = end-start;
    cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" <<endl;
    delete mergesort;


    ParallelMergeSort *parallelMergeSort= new ParallelMergeSort(&nums1);
    start = chrono::high_resolution_clock::now();
    parallelMergeSort->sort();
    
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> parallelMergeSortDuration = end-start;
    cout << "ParallelMergeSort time taken: " << parallelMergeSortDuration.count() << " seconds" << endl;
    delete parallelMergeSort;

}