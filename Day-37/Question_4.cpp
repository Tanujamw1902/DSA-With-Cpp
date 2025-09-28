#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int,int>>> tweets; // userId -> [(time, tweetId)]
    
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int,int>> pq; // max heap by timestamp
        
        // include self
        followees[userId].insert(userId);
        
        // collect tweets of self and followees
        for (int uid : followees[userId]) {
            for (auto &t : tweets[uid]) {
                pq.push(t);
            }
        }
        
        // get top 10
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        
        // remove self from followees (optional, maintain original state)
        followees[userId].erase(userId);
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            followees[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    vector<int> feed = twitter.getNewsFeed(1);
    for (int id : feed) cout << id << " ";
    cout << endl;
    
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    feed = twitter.getNewsFeed(1);
    for (int id : feed) cout << id << " ";
    cout << endl;
    
    twitter.unfollow(1, 2);
    feed = twitter.getNewsFeed(1);
    for (int id : feed) cout << id << " ";
    cout << endl;
    
    return 0;
}