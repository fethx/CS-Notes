#include<iostream>
#include<vector>
using namespace std;

// O(nlg(n)) O(1) 非稳定排序，原地排序, 最差O(n^2)
int partition(vector<int>& vec, int l, int r) {
    int key = vec[l];

    // [l + 1, j] [j + 1, i - 1]
    int j = l;
    for(int i = l + 1; i < vec.size(); ++i) {
        if(vec[i] < key) {
            swap(vec[i], vec[j + 1]);
            ++j;
        }
    }
    swap(vec[l], vec[j]);
    return j;
}

void quick_sort(vector<int>& vec, int l, int r) {
    if(l >= r) return;

    int idx = partition(vec, l, r);
    quick_sort(vec, l, idx - 1);
    quick_sort(vec, idx + 1, r);
}
