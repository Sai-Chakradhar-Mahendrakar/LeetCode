class Twitter {
public:
    unordered_set<int> user[501];
    vector<pair<int, int>> tweet;

    Twitter() {}
    
    // T:O(1) S:O(n)
    void postTweet(int userId, int tweetId) {
        tweet.push_back({tweetId, userId});
    }
    // T:O(n) S:(1)
    vector<int> getNewsFeed(int userId) {
        int t=tweet.size();
        vector<int> ans;
        for(int i=t-1;i>=0 && ans.size()<10;i--){
            if(tweet[i].second==userId || user[userId].find(tweet[i].second)!=user[userId].end()){
                ans.push_back(tweet[i].first);
            }
        }
        return ans;
    }
    // T:O(1) S:(1)
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }
    // T:O(1) S:(1)
    void unfollow(int followerId, int followeeId) {
        if(user[followerId].find(followeeId)!=user[followerId].end()){
            user[followerId].erase(followeeId);
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