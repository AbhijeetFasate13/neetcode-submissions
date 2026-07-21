class Solution {
    int sumOfSquareOfDigits(int n){
        int sum = 0;
        while(n){
            sum += pow(n%10,2);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(fast!=1 and sumOfSquareOfDigits(fast)!=1){
            slow = sumOfSquareOfDigits(slow);
            fast = sumOfSquareOfDigits(sumOfSquareOfDigits(fast));
            if(slow==fast){
                return false;
            }
        }
        return true;
    }
};
