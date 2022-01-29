class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int dupcount = 1;
        int maxdup = 2;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[l]) {
                l++;
                dupcount = 1; // 重置
                swap(nums[i], nums[l]);
            } 
            else {
                dupcount++;
                if(dupcount <= maxdup) {
                    l++;
                    swap(nums[i], nums[l]);
                }
            }
        }
        return l + 1;
    }
};