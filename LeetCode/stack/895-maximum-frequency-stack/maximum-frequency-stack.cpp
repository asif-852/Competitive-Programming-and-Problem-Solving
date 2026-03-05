class FreqStack {
public:
    int maxFreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> tracker;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        tracker[freq[val]].push(val);
    }
    
    int pop() {
        int res = tracker[maxFreq].top();
        tracker[maxFreq].pop();
        freq[res]--;
        if(tracker[maxFreq].empty()) {
            maxFreq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */