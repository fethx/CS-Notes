#include <iostream>
#include <vector>
using namespace std;

// O(n^2) O(1) 原地算法，稳定
void bubble_sort(vector<int>& vec) {
    for(int i = 0; i < vec.size() - 1; ++i) {
        for(int j = 0; j < vec.size() - 1 - i; ++j) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// 添加一个flag, 如果一轮没有交换，就说明已经排序完成
void bubble_sort_optimize(vector<int>& vec) {
    bool sorted = true;
    for(int i = 0; i < vec.size() - 1; ++i) {
        for(int j = 0; j < vec.size() - 1 - i; ++j) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                sorted = false;
            }
        }
        if(sorted) {
            std::cout << "use sorted flag" << "\n";
            break;
        }
    }
}