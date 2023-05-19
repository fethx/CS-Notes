
# 前言

按照[费曼学习法](./methodology/Feynman_Technique.md)的理论，学习要有输出。计算机知识很多很杂，要落实到代码上，亲自动手，才能真正学会。

因此，在学习的过程中，知识点落实到代码上，落实到文字总结上。这就是创建这个项目的初衷，记录总结回顾。


# C++
## 面向对象编程 OOP(Object Oriented Programming)

### C++ 面向对象三大特性: 
1. Encapsulation - 封装 
2. Inheritance - 继承
3. Polymorphism - 多态


<!-- ### 虚函数

## 智能指针

## 右值引用，移动语义，完美转发 -->



# 算法
一些常见的算法，比如排序。

## 排序算法 
| 算法名称 | 平均时间复杂度 | 最好情况  | 最坏情况 | 空间复杂度 | 排序方式  | 稳定性 |
| :------: | :------------: | :-------: | :------: | :--------: | :-------: | :----: |
| 冒泡排序 |     O(n^2)     |   O(n)    |  O(n2)   |    O(1)    | In-place  |  稳定  |
| 选择排序 |     O(n2)      |   O(n2)   |  O(n2)   |    O(1)    | In-place  | 不稳定 |
| 插入排序 |     O(n2)      |   O(n)    |  O(n2)   |    O(1)    | In-place  |  稳定  |
| 快速排序 |    O(nlogn)    | O(nlogn)  |  O(n2)   |  O(logn)   | In-place  | 不稳定 |
| 归并排序 |    O(nlogn)    | O(nlogn)  | O(nlogn) |    O(n)    | Out-place |  稳定  |
|  堆排序  |    O(nlogn)    | O(nlogn)  | O(nlogn) |    O(1)    | In-place  | 不稳定 |
| 希尔排序 |    O(nlogn)    | O(nlog2n) |  O(n2)   |    O(1)    | In-place  | 不稳定 |
| 计数排序 |     O(n+k)     |  O(n+k)   |  O(n+k)  |    O(k)    | Out-place |  稳定  |
|  桶排序  |     O(n+k)     |  O(n+k)   |  O(n2)   |   O(n+k)   | Out-place |  稳定  |
| 基数排序 |     O(n*k)     |   O(nk)   |  O(nk)   |   O(n+k)   | Out-place |  稳定  |

注：
- In-place: 不需要额外的空间,原地修改序列实现算法。其空间复杂度为O(1)。
- Out-place: 需要额外的空间来实现算法。其空间复杂度一般为O(n)或O(k)等。
- 稳定性：稳定的排序算法会保持相同元素的相对位置不变。

通常会把它们分为三类：[^1]
1. 选择排序、插入排序、冒泡排序
2. 堆排序、归并排序、快速排序
3. 计数排序、基数排序 、桶排序

前两类是基于比较的排序算法。对n个元素进行排序时， 若元素比较大小的时间复杂度为O(1)，则第一类排序算法的时间复杂度为O(n^2)，第一类排序算法的时间复杂度为O(nlogn)。实际上，基于比较的排序算法的时间复杂度下 界为O(nlogn)。  
第三类不直接比较大小，而是对被排序的数值采取按位划分、分类映射等处理方式。其时间复杂度不仅与 n 有关，还与数值的大小范围 m 有关。 



# 刷题
这里记录刷过的算法题。

[LeetCode Top 100 Liked Questions](https://leetcode.com/problem-list/top-100-liked-questions/)

| #   | Title                                                | Solution                        | Difficulty | Topics            | Others |
| --- | ---------------------------------------------------- | ------------------------------- | ---------- | ----------------- | ------ |
| 1   | [1. Two Sum](https://leetcode.com/problems/two-sum/) | [C++](./leetcode/array/lc1.cpp) | Easy       | Array, Hash Table |



# 参考资料
[^1]:<a id="ref1">《算法竞赛进阶指南》李煜东</a>

<!-- 1. 《算法笔记》 胡凡
2. *C++ Primer (5th Edition)*
3. *Effective Modern C++* -->

