class Solution {
    class cmp {
       public:
        bool operator()(const vector<int>& a, const vector<int>& b) {
            double euclideanDist1 = sqrt(a[0] * a[0] + a[1] * a[1]);
            double euclideanDist2 = sqrt(b[0] * b[0] + b[1] * b[1]);
            return euclideanDist1 <= euclideanDist2;
        }
    };

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,cmp>pq;
        for(const auto& i:points)pq.push(i);
        while(pq.size()>k)pq.pop();
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
