#include<iostream>
#include<vector>
#include<limits>
using namespace std;

// O(nlogn) O(n) 空间换时间, 稳定

// l <= mid < r.
void merge(vector<int>& vec, int l, int mid, int r) {
    vector<int> L, R;
    for(int i = 0; i < mid - l + 1; ++i)
        L.push_back(vec[l + i]);
    for(int j = 0; j < r - mid; ++j)
        R.push_back(vec[mid + j + 1]);

    int i = 0;
    int j = 0;
    for(int k = l; k <= r; ++k) {
        if(i >= L.size()) {
            vec[k] = R[j];
            ++j;
        } else if(j >= R.size()) {
            vec[k] = L[i];
            ++i;
        } else if(L[i] <= R[j]) { // 稳定的关键在这里, 稳定-->可以实现稳定，不稳定-->不可以实现
            vec[k] = L[i]; 
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
    }
}

// The initial call merge_sort(vec, 0, vec.size()-1)
void merge_sort_TD(vector<int>& vec, int l, int r) {
    if(l >= r) return;

    int mid = (r - l) / 2 + l;
    merge_sort_TD(vec, l, mid);
    merge_sort_TD(vec, mid + 1, r);
    merge(vec, l, mid, r);
}

void merge_sort_BU(vector<int>& vec) {
    for(int sz = 1; sz < vec.size(); sz += sz) {
        for(int i = 0; i + sz < vec.size(); i += sz + sz ) {
            // [i, i + sz -1], [i + sz, i + sz + sz -1]
            merge(vec, i, i + sz - 1, min(i + sz + sz - 1, int(vec.size()) - 1));
        }
    }
}
