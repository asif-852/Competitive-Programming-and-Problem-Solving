class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tracker;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tracker[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int pos = upper_bound(tracker[key].begin(), tracker[key].end(), pair<int, string>{timestamp, "{"}) - tracker[key].begin() - 1;
        if(pos >= 0) {
            return tracker[key][pos].second;
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */