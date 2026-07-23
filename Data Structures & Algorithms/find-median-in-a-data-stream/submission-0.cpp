class MedianFinder {
    priority_queue<int> bottomHalf;
    priority_queue<int, vector<int>, greater<int>> topHalf;

   public:
    MedianFinder() {}

    void addNum(int num) {
        bottomHalf.push(num);

        topHalf.push(bottomHalf.top());
        bottomHalf.pop();

        if (topHalf.size() > bottomHalf.size()) {
            bottomHalf.push(topHalf.top());
            topHalf.pop();
        }
    }

    double findMedian() {
        if (bottomHalf.size() - topHalf.size() == 0) {
            return (bottomHalf.top() + topHalf.top()) / 2.0;
        }
        return bottomHalf.top();
    }
};
