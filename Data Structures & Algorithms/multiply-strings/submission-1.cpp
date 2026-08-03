class Solution {
private:
    string add(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        if (m < n) {
            return add(num2, num1);
        }

        int i = m - 1;
        int j = n - 1;
        int carry = 0;
        int sum = 0;

        while (i >= 0 && j >= 0) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;

            num1[i] = sum + '0';

            --i;
            --j;
        }

        while (i >= 0) {
            int digit1 = num1[i] - '0';

            sum = digit1 + carry;
            carry = sum / 10;
            sum %= 10;

            num1[i] = sum + '0';

            --i;
        }

        if (carry) {
            return to_string(carry) + num1;
        }

        return num1;
    }

public:
    string multiply(string num1, string num2) {
        if (num2.empty()) {
            return "";
        }

        if (num2 == "1") {
            return num1;
        }

        if (num2 == "0") {
            return "0";
        }

        int multiplier = num2.back() - '0';
        num2.pop_back();

        int n = num1.size();
        int carry = 0;

        string original = num1;

        for (int i = n - 1; i >= 0; --i) {
            int digit = num1[i] - '0';

            int product = digit * multiplier + carry;
            carry = product / 10;
            product %= 10;

            num1[i] = product + '0';
        }

        if (carry) {
            num1 = to_string(carry) + num1;
        }

        string answer = multiply(original, num2);
        answer.push_back('0');

        return add(num1, answer);
    }
};