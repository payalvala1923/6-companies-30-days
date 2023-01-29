class TweetCounts {
public:
    //1348. Tweet Counts Per Frequency
    unordered_map<string, vector<int>> m;
    unordered_map<string, int> f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector <int> ans;
        for (int i=0; i <= (endTime - startTime) / f[freq]; i++)
            ans.push_back(0);

        for (auto& time : m[tweetName]) {
            if (time >= startTime && time <= endTime) {
                int i = (time - startTime) / f[freq];
                ans[i]++;
            }
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
