#include <iostream>
#include <vector>
using namespace std;

// O(n^2) O(1) 非稳定排序，原地排序
void select_sort(vector<int>& vec) {
    for(int i = 0; i < vec.size() - 1; ++i) {
        int min_index = i;
        for(int j = i + 1; j < vec.size(); ++j) {
            if(vec[min_index] > vec[j]) {
                min_index = j;
            }
        }
        swap(vec[i], vec[min_index]);
    }
}