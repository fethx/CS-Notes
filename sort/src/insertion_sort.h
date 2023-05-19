#include<iostream>
#include<vector>
using namespace std;

// O(n^2) O(1) 稳定排序，原地排序
void insertion_sort(vector<int>& vec) {
    for(int i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        // Insert A[j] into the sorted sequence A[0..j-1]. 
        int j = i - 1;
        while(j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}