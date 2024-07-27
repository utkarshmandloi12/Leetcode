class Solution {
public:
    int countEven(int num) {
        int num2 = num, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if ((sum % 2 == 1 && num2 % 2 == 0)) {
            return num2 / 2 - 1;
        } else {
            return num2 / 2;
        }
    }
};