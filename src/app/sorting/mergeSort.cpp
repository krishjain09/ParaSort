#include "mergeSort.hpp"


MergeSort::MergeSort(vector<int>*nums){
    this->nums = nums;
}

MergeSort::~MergeSort(){}

void MergeSort::merge(vector<int>*nums,int left,int mid,int right){
    vector<int>result;
    int i=left;
    int j=mid+1;
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
}
void MergeSort::recursiveSort(int left, int right){
    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;
    recursiveSort(left,mid);
    recursiveSort(mid+1,right);
    merge(nums,left,mid,right);
}


void MergeSort::sort(){
    if((*nums).size()==0){
        exit(1);
    }
    recursiveSort(0,(*nums).size()-1);
}
