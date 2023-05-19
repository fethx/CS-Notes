#include "bubble_sort.h"
#include "select_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"

void print(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {  
    // 1. bubble_sort
    // vector<int> A = {5, 2, 4, 6, 1, 3};
    // bubble_sort(A);
    vector<int> A = {1, 2, 3, 4, 5, 6};
    bubble_sort_optimize(A);
    print(A);

    // // 2. select_sort
    // vector<int> A = {5, 2, 4, 6, 1, 3};
    // select_sort(A);
    // print(A);

    // // 3. insertion_sort
    // vector<int> A = {5, 2, 4, 7, 1, 3, 2, 6};
    // insertion_sort(A);
    // print(A);

    // // 4. quick_sort
    // vector<int> A = {5, 2, 4, 7, 1, 3, 2, 6};
    // quick_sort(A, 0, 7);
    // print(A);

    // // 5. shell_sort
    // vector<int> A = {5, 2, 4, 7, 1, 3, 2, 6};
    // shell_sort(A);
    // print(A);

    // // 6. merge_sort
    // vector<int> A = {5, 2, 4, 6, 1, 3};
    // // merge_sort_TD(A, 0, 5);
    // merge_sort_BU(A);
    // print(A);

    // // 7. heap_sort
    // vector<int> AA = {4, 1, 2, 3, 16, 9, 10, 14, 8, 7};
    // Max_heap A = Max_heap(AA);
    // heap_sort(A);
    // print(A.v);

    // // 8. counting_sort
    // vector<int> A{2, 5, 3, 0, 2, 3, 0, 3};
    // vector<int> B(8);
    // counting_sort(A, B, 5);
    // print(B);

    // 9. bucket_sort


    // // 10. radix_sort
    // vector<int> A{329, 457, 657, 839, 436, 720, 355};
    // radix_sort(A, 3);
    // print(A);

    return 0;
}

