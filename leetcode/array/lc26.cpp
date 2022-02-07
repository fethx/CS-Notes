// Solution 1, two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0; // 数组为空
        int l = 0; // 维护l在最后一个不重复的数字上
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[l]) {
                l++;
                swap(nums[i], nums[l]);
            }
        }
        return l + 1;
    }
};


// Solution 2, brilliant
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums) {
            if(i < 1 || nums[i - 1] < n)
                nums[i++] = n;
        }
        return i;
    }
};