class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                if(i != l) {
                    swap(nums[i], nums[l]);
                    l++;
                } 
                else {
                    l++;
                }
            } 
        }
        return l;
    }
};