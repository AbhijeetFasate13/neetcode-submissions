class CountSquares {
    unordered_map<int, vector<vector<int>>> xParallel, yParallel;
    map<vector<int>, int> allPoints;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        xParallel[point[0]].push_back(point);
        yParallel[point[1]].push_back(point);
        allPoints[point]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;

        for (const auto& i : xParallel[x]) {
            if (i[1] == y) continue;
            for (const auto& j : yParallel[y]) {
                if (j[0] == x) continue;
                if (abs(y - i[1]) == abs(x - j[0])) {
                    auto it = allPoints.find({j[0], i[1]});
                    if (it != allPoints.end()) ans += it->second;
                }
            }
        }

        return ans;
    }
};
