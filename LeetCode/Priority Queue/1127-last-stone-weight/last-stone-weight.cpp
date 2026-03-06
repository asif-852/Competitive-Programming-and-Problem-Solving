class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stonesQueue(stones.begin(), stones.end());
        while(stonesQueue.size() > 1) {
            int y = stonesQueue.top();
            stonesQueue.pop();
            int x = stonesQueue.top();
            stonesQueue.pop();
            if(x != y) {
                stonesQueue.push(y - x);
            }
        }
        return stonesQueue.empty() ? 0 : stonesQueue.top();
    }
};