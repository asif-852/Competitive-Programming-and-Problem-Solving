class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        vector<int>& A = nums1, & B = nums2;
        int m = A.size(), n = B.size();
        int l = 0, r = m;
        int half = (m + n + 1) / 2;
        double ans = -1;
        while(l <= r) {
            int i = (l + r) >> 1;
            int j = half - i;

            int Aleft = (i > 0) ? A[i - 1] : -2e9;
            int Aright = (i < m) ? A[i] : 2e9;
            int Bleft = (j > 0) ? B[j - 1] : -2e9;
            int Bright = (j < n) ? B[j] : 2e9;

            if(Aleft <= Bright && Bleft <= Aright) {
                ans = ((m + n) & 1) ? max(Aleft, Bleft) : (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                break;
            } else {
                (Aleft > Bright) ? r = i - 1 : l = i + 1;
            } 
        }
        return ans;
    }
};