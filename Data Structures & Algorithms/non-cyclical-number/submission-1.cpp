class Solution {
    int sumOfSquareOfDigits(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = sumOfSquareOfDigits(n);
        int fast = sumOfSquareOfDigits(slow);
        while(slow != 1 and fast != 1){
            if(slow==fast){
                return false;
            }
            slow = sumOfSquareOfDigits(slow);
            fast = sumOfSquareOfDigits(sumOfSquareOfDigits(fast));
        }
        return true;
    }
};
