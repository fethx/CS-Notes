class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0; // 维护"000"的左边界
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) {
                if(i != l) {
                    swap(nums[l], nums[i]);
                    l++;
                }
                else {
                    l++;
                }
            }
        }
    }
};