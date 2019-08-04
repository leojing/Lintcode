//
//  main.cpp
//  Lintcode-501
//
//  Created by Jing LUO on 7/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

class Tweet {
public:
    int id;
    int user_id;
    std::string text;
    Tweet(int userid, std::string tweet_text) {
        // This will create a new tweet object,
        // and auto fill id
        user_id = userid;
        text = tweet_text;
    }
};

class Node {
public:
    int order;
    Tweet tweet = Tweet(0, ""); // 在lintcode提交的代码中,不需要初始化,否则wrong answer
    Node(int o, Tweet t)
    {
        order = o;
        tweet = t;
    }

    bool operator<(const Node &o) const
    {
        return order > o.order;
    }
};

class MiniTwitter {
public:
    int order;
    std::map<int, std::set<int>> friends;
    std::map<int, std::vector<Node>> user_tweets;

    MiniTwitter() {
        order = 0;
        friends.clear();
        user_tweets.clear();
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
    Tweet postTweet(int user_id, std::string tweet_text) {
        Tweet tweet = Tweet(user_id, tweet_text);
        if (user_tweets.find(user_id) == user_tweets.end())
            user_tweets[user_id] = std::vector<Node>();
        order += 1;
        user_tweets[user_id].push_back(Node(order, tweet));
        return tweet;
    }

    std::vector<Node> helper(std::vector<Node> &first, std::vector<Node> &second) {
        std::vector<Node> result;
        int i = 0, j = 0;
        while (i < first.size() && j < second.size()) {
            if (first[i].order > second[j].order) {
                result.push_back(first[i]);
                ++ i;
            } else {
                result.push_back(second[j]);
                ++ j;
            }
        }
        while (i < first.size()) {
            result.push_back(first[i]);
            ++ i;
        }
        while (j < second.size()) {
            result.push_back(second[j]);
            ++ j;
        }
        return result;
    }

    std::vector<Node> mergeTweets(std::vector<std::vector<Node>> &tweets, int start, int end) {
        if (start + 1 < end) {
            int mid = start + (end - start) / 2;
            std::vector<Node> left = mergeTweets(tweets, start, mid);
            std::vector<Node> right = mergeTweets(tweets, mid + 1, end);
            return helper(left, right);
        }
        if (start == end) {
            return tweets[start];
        }
        return helper(tweets[start], tweets[end]);
    }

    void getTen(std::vector<Node> &nodes, std::vector<Node> &input) {
        int tweetsSize = int(input.size());
        int count = 0;
        while (count < tweetsSize && count < 10) {
            nodes.push_back(input[count]);
            count ++;
        }
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    std::vector<Tweet> getNewsFeed(int user_id) {
        std::vector<Tweet> result;
        std::vector<std::vector<Node>> nodesList;
        std::set<int>::iterator iter;
        if (user_tweets.find(user_id) == user_tweets.end()) {
            user_tweets[user_id] = std::vector<Node>();
        }
        std::sort(user_tweets[user_id].begin(), user_tweets[user_id].end());
        nodesList.push_back(user_tweets[user_id]);
        for (iter = friends[user_id].begin(); iter != friends[user_id].end(); ++ iter) {
            int userId = *iter;
            std::vector<Node> nodes = std::vector<Node>();
            if (user_tweets.find(user_id) != user_tweets.end()) {
                nodes = user_tweets[userId];
            }
            std::vector<Node> tenNodes;
            getTen(tenNodes, nodes);
            std::sort(tenNodes.begin(), tenNodes.end());
            nodesList.push_back(tenNodes);
        }
        std::vector<Node> allNodes = mergeTweets(nodesList, 0, int(nodesList.size())-1);
        int count = 0;
        while (count < allNodes.size() && count < 10) {
            Node node = allNodes[count];
            result.push_back(node.tweet);
            count ++;
        }
        return result;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    std::vector<Tweet> getTimeline(int user_id) {
        if (user_tweets.find(user_id) == user_tweets.end()) {
            return std::vector<Tweet>();
        }
        std::vector<Node> allTweets = user_tweets[user_id];
        std::sort(allTweets.begin(), allTweets.end());
        std::vector<Tweet> timeLine;
        int count = 0;
        while (count < allTweets.size() && count < 10) {
            Node node = allTweets[count];
            timeLine.push_back(node.tweet);
            count ++;
        }
        return timeLine;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        if (friends.find(from_user_id) == friends.end()) {
            friends[from_user_id] = std::set<int>();
        }
        friends[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        if (friends.find(from_user_id) == friends.end()) {
            return;
        }
        friends[from_user_id].erase(to_user_id);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    MiniTwitter twitter = MiniTwitter();
    twitter.postTweet(1, "1");
    twitter.getNewsFeed(1);
    twitter.getTimeline(1);
    twitter.follow(2, 1);
    twitter.follow(1, 4);
    twitter.follow(1, 2);
    twitter.follow(1, 3);
    twitter.postTweet(1, "2");
    twitter.postTweet(2, "3");
    twitter.postTweet(3, "4");
    twitter.postTweet(4, "5");
    twitter.getNewsFeed(2);
    twitter.postTweet(4, "6");
    twitter.postTweet(2, "7");
    twitter.postTweet(2, "8");
    twitter.postTweet(4, "9");
    twitter.postTweet(4, "10");
    twitter.postTweet(3, "11");
    twitter.postTweet(2, "12");
    twitter.postTweet(1, "13");
    twitter.postTweet(1, "14");
    twitter.postTweet(3, "15");
    twitter.postTweet(4, "16");
    twitter.postTweet(1, "17");
    twitter.postTweet(2, "18");
    twitter.getTimeline(12);
    twitter.getNewsFeed(1);
    return 0;
}
