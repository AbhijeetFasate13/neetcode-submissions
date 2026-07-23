class Tweet {
   public:
    int id;
    int time;

    Tweet(int id, int time) {
        this->id = id;
        this->time = time;
    }

    bool operator<(const Tweet& other) const {
        if (time == other.time) return id < other.id;
        return time < other.time;
    }
};

class Twitter {
    int timer;
    unordered_map<int, unordered_set<int>> userMap;
    unordered_map<int, set<Tweet>> tweetMap;

    class cmp {
       public:
        bool operator()(const Tweet& a, const Tweet& b) const { return a.time > b.time; }
    };

   public:
    Twitter() { timer = 0; }

    void addUser(int userId) {
        if (!userMap.count(userId)) {
            userMap[userId] = {};
        }
    }

    void postTweet(int userId, int tweetId) {
        addUser(userId);
        tweetMap[userId].insert(Tweet(tweetId, ++timer));
    }

    vector<int> getNewsFeed(int userId) {
        addUser(userId);

        priority_queue<Tweet, vector<Tweet>, cmp> pq;

        auto processUser = [&](int uid) {
            for (const auto& tweet : tweetMap[uid]) {
                if (pq.size() == 10 && tweet < pq.top()) {
                    continue;
                }

                pq.push(tweet);

                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        };

        processUser(userId);

        for (int followee : userMap[userId]) {
            processUser(followee);
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().id);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        addUser(followerId);
        addUser(followeeId);

        userMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        addUser(followerId);
        addUser(followeeId);

        userMap[followerId].erase(followeeId);
    }
};