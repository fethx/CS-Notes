#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// o(nlog(n))  O(1) 不稳定
// use vector to implement a max heap. reference: CLRS
class Max_heap {
public:
    int size;
    int heap_size;
    vector<int> v;
    Max_heap(vector<int> v);
    int parent(int i);
    int left(int i);
    int right(int i);
};
Max_heap::Max_heap(vector<int> vv)
{
    size = vv.size();
    heap_size = vv.size();
    v = vv;
}
int Max_heap::parent(int i)
{
    return i / 2;
}
int Max_heap::left(int i)
{
    return 2 * i;
}
int Max_heap::right(int i)
{
    return 2 * i + 1;
}

void max_heapify(Max_heap& A, int i) 
{
    int l = A.left(i);
    int r = A.right(i);
    int largest = 0;
    if(l <= A.heap_size && A.v[l - 1] > A.v[i - 1])
        largest = l;
    else
        largest = i;
    if(r <= A.heap_size && A.v[r - 1] > A.v[largest - 1])
        largest = r;
    if(largest != i) {
        swap(A.v[i-1], A.v[largest-1]);
        max_heapify(A, largest); // after swap, largest equal to the index of v[i].
    }
}

void build_max_heap(Max_heap& A)
{
    // A.heap_size = A.size(); 
    for(int i = A.size / 2; i > 0; --i) {
        max_heapify(A, i);
    }
}

void heap_sort(Max_heap& A) {
    build_max_heap(A);
    for(int i = A.size; i > 1; --i) {
        swap(A.v[0], A.v[i-1]);
        A.heap_size--;
        max_heapify(A, 1); // In heap, 1th indice must be 1.
    }
}
