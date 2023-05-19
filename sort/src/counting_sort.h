#include<iostream>
#include<vector>
using namespace std;

// O(nk) O(n + k) 稳定
void counting_sort(vector<int> A, vector<int>& B, int k)
{
    vector<int> C(k + 1);
    for(int i = 0; i <= k; ++i)
        C.push_back(0);
    for(int j = 0; j < A.size(); ++j)
        C[A[j]] += 1;
    // C[i] now contains the number of elements equal to i.
    for(int i = 1; i <= k; ++i)
        C[i] += C[i-1];
    // C[i] now contains the number of elements less than or equal to i.
    for(int j = A.size() - 1; j >= 0; --j) {  // 此处逆序是为了保持相同键值的稳定性
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}