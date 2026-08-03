class Solution {
    string add(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m < n)return add(num2, num1);
        int ptr1 = m - 1, ptr2 = n - 1;
        int sum = 0, carry = 0;
        while (ptr1 >= 0 and ptr2 >= 0) {
            int d1 = num1[ptr1] - '0';
            int d2 = num2[ptr2] - '0';
            sum = d1 + d2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            num1[ptr1] = sum + '0';
            ptr1--;
            ptr2--;
        }
        while (ptr1 >= 0) {
            int d1 = num1[ptr1] - '0';
            sum = d1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            num1[ptr1] = sum + '0';
            ptr1--;
        }
        if (carry) {
            return to_string(carry) + num1;
        }
        return num1;
    }

   public:
    string multiply(string num1, string num2) {
        if (num2.empty()) return "";
        if (num2 == "1") return num1;
        if (num2 == "0") return "0";
        int mult = num2.back()-'0';
        num2.pop_back();
        int n = num1.size();
        int carry = 0;
        string temp = num1;
        for (int i = n - 1; i >= 0; i--) {
            int d = num1[i] - '0';
            int prod = (d * mult) + carry;
            carry = prod / 10;
            prod %= 10;
            num1[i] = prod + '0';
        }
        if (carry) {
            num1 = to_string(carry) + num1;
        }
        string ans = multiply(temp, num2);
        ans.push_back('0');
        return add(num1, ans);
    }
};
