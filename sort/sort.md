# 十大排序算法

## 冒泡排序

图示[^1]
![bubble_sort.gif](../images/bubble_sort.gif)

冒泡排序是一种简单的排序算法，其时间复杂度为O(n^2)。该算法由n轮组成，在每一轮中，它遍历数组中的元素。每当找到两个相邻的元素处于错误的顺序时，算法会交换它们。该算法可以如下实现[^2]：

```c++
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
        if (array[j] > array[j+1]) {
            swap(array[j],array[j+1]);
        }
    }
}
```
在第一轮冒泡排序之后，最大的元素将处于正确的位置，更一般地，经过k轮冒泡排序后，k个最大的元素将处于正确的位置。因此，经过n轮冒泡排序后，整个数组将被排序。

简单来说，冒泡排序就是两两比较，每一轮将(未排序序列)最大值移到(未排序序列)最右边。可优化的地方是如果一轮比较下来没有交换元素，就说明已经排序完成，可以提前终止。


# 参考资料
[^1]:<a id="ref1"> https://visualgo.net/en </a>  

[^2]:<a id="ref1"> *Guide to Competitive Programming: Learning and Improving Algorithms Through Contests Second Edition by Antti Laaksonen*</a>

