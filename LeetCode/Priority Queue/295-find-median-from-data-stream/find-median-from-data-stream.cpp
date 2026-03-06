class MedianFinder {
public:
    
    priority_queue<int> max_heap;   // max_heap stores the lower half of the sorted stream
    priority_queue<int, vector<int>, greater<int>> min_heap;  // min_heap stores the upper half of the sorted stream
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //Add the new number to the max_heap (lower half)
        max_heap.push(num);
        
        // Move the largest element from the lower half into the upper half
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        // Max_heap must always be the same size as min_heap, or exactly 1 element larger
        if(min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */