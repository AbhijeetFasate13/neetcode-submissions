class TimeMap {
    map<string, map<int, string>> mp;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key][timestamp] = value; }

    string get(string key, int timestamp) {
        auto mit = mp.find(key);
        if (mit == mp.end()) return "";

        auto& m = mit->second;
        auto it = m.upper_bound(timestamp);

        if (it == m.begin()) return "";

        --it;
        return it->second;
    }
};
