class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> idx;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idx.count(val)) {
            return false;
        }
        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!idx.count(val)) {
            return false;
        }
        int toRemove = idx[val];
        int lastval = nums.back();

        nums[toRemove] = lastval;
        idx[lastval] = toRemove;
        
        idx.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        int randIdx = (rand() % n + n) % n;
        return nums[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */