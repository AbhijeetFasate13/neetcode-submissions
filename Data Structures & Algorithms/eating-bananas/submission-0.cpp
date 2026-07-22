class Solution {
    bool check(const int& m, const int& h, const vector<int>&piles){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += ceil(piles[i]/(m*1.0));
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(),piles.end())+1;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(check(m,h,piles)){
                r = m;
            }else{
                l = m;
            }
        }
        return r;
    }
};
