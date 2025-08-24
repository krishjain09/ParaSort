#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include<vector>
#include <stdlib.h>
using namespace std;

class MergeSort{
    private:
        vector<int> *nums;
    public:
        MergeSort(vector<int>*nums);
        ~MergeSort();
        void sort();
        void recursiveSort(int left,int right);
        void merge(vector<int>*nums,int left,int mid,int right);
};

#endif