class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> p;
        vector<pair<int, int>> v(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            v[i].first = nums[i];
            v[i].second = i;
        }
        sort(v.begin(), v.end());

	    for(int i = 0, j = nums.size() - 1; i < j;) {
		    if(v[i].first + v[j].first == target) {
			    p.push_back(v[i].second);
                p.push_back(v[j].second);
			    break;
		    } else {
                (v[i].first + v[j].first < target) ? i++ : j--;
            }
	    }
	    return p;
    }
};