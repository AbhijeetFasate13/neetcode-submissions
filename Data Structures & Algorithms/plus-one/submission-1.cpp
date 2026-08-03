class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0, carry = 1;
        int n = (int)digits.size();
        vector<int>ans(n);
        for(int i = n-1;i>=0;i--){
            sum = (digits[i]+carry)%10;
            carry = (digits[i]+carry)/10;
            ans[i]=sum;
        }
        if(carry){
            reverse(ans.begin(),ans.end());
            ans.push_back(carry);
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};
