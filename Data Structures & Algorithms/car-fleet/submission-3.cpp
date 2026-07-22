class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i] ={position[i],speed[i]};
        }
        sort(arr.rbegin(),arr.rend());
        int fleets = 1;
        double prevTime = (target-arr[0].first)/(arr[0].second*1.0);
        for(int i=1;i<n;i++){
            double currTime = (target-arr[i].first)/(arr[i].second*1.0);
            if(currTime>prevTime){
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};