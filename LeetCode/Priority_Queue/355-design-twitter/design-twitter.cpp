class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);
        priority_queue<array<int, 4>> pq;
        for(auto& id : followees[userId]) {
            if(tweets[id].empty()) {
                continue;
            }
            int lastindex = tweets[id].size() - 1;
            auto [time, tweetId] = tweets[id][lastindex];
            pq.push({time, id, tweetId, lastindex});
        }
        vector<int> res;
        while(res.size() < 10 && !pq.empty()) {
            auto [time, id, tweetId, lastindex] = pq.top();
            pq.pop();
            res.push_back(tweetId);
            if(lastindex > 0) {
                auto [time, tweetId] = tweets[id][--lastindex];
                pq.push({time, id, tweetId, lastindex});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followees[followerId].count(followeeId)) {
            followees[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */