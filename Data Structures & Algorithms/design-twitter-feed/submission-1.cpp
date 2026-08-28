class Twitter {
private:    
    int count;
    unordered_map<int,set<int>> following;
    unordered_map<int,vector<pair<int,int>>> tweets;
public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        vector<pair<int,int>> temp;
        for(auto it:following[userId]){
            for(auto it2:tweets[it]){
                temp.push_back(it2);
            }
        }

        for(auto it:tweets[userId]) temp.push_back(it);

        sort(temp.begin(),temp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first>b.first;
        });

        for(int i=0; i<10; i++){
            if(i<temp.size()) feed.push_back(temp[i].second);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
