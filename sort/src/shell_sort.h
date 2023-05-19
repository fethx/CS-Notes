#include<iostream>
#include<vector>
using namespace std;

// O( n^2 * log(n)) O(1) 不稳定, 分在不同的组中而导致它们的顺序发生变化。

// In insert_sort, gap == 1.
void insert_gap(vector<int>& vec, int gap, int i) {
    int key = vec[i];
    int j = i - gap;
    while(j >= 0 && vec[j] > key) {
        vec[j + gap] = vec[j];
        j -= gap;
    }
    vec[j + gap] = key;
}

void shell_sort(vector<int>& vec) {
    for(int gap = vec.size() / 2; gap > 0; gap /= 2) {
        for(int i = 1; i < vec.size(); ++i) {
            insert_gap(vec, gap, i);
        }
    }
}

