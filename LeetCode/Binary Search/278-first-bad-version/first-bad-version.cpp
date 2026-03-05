// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n, ans = -1;
        while(l <= r) {
            long long mid = l + r >> 1;
            isBadVersion(mid) ? r = mid - 1, ans = mid : l = mid + 1;
        }
        return ans;
    }
};