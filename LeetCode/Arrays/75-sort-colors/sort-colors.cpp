class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 1) {
                mid++;
            } else {
                nums[mid] == 0 ? swap(nums[low++], nums[mid++]) : swap(nums[high--], nums[mid]);
            }
        }
    }
};