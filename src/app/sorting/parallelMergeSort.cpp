#include "parallelMergeSort.hpp"

ParallelMergeSort::ParallelMergeSort(vector<int>*nums){
    this->nums=nums;
};

ParallelMergeSort::~ParallelMergeSort(){};

void ParallelMergeSort::merge(vector<int>*nums,int left,int mid,int right){
    int i=left;
    int j=mid+1;
    vector<int>result;

    while(i<=mid && j<=right){
        if((*nums)[i]<(*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        }else{
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while(i<=mid){
        result.push_back((*nums)[i]);
        i++;
    }

    while(j<=right){
        result.push_back((*nums)[j]);
        j++;
    }
    int k=0;
    for(int i=left;i<=right;i++){
        (*nums)[i]=result[k++];
    }
};

void ParallelMergeSort::recursiveSort(int left,int right){

    const int THRESHOLD = 5000;

    if(right - left < THRESHOLD){
        std::sort((*nums).begin()+left,(*nums).begin()+right+1);
        return;
    }

    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;
    thread thread1([this,left,mid]{this->recursiveSort(left,mid);});
    thread thread2([this,mid,right]{this->recursiveSort(mid+1,right);});
    thread1.join();
    thread2.join();
    merge(nums,left,mid,right);
}


void ParallelMergeSort::sort(){
    if((*nums).size()==0){
        exit(1);
    }
    thread thread_1([this]{this->recursiveSort(0,(*nums).size()-1);});
    thread_1.join();
}