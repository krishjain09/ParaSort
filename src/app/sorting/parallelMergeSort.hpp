#ifndef ParallelMergeSort_HPP
#define ParallelMergeSort_HPP
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <thread>
using namespace std;
class ParallelMergeSort{
    private:
        vector<int>*nums;
    public:
        ParallelMergeSort(vector<int>*nums);
        ~ParallelMergeSort();
        void sort();
        void recursiveSort(int left,int right);
        void merge(vector<int>*nums,int left,int mid,int right);
};

#endif