class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long int num = n, count = 0, temp1, temp0;
        while (num > 0) {
            if (count == 0) {
                temp0 = num % 2;
            } else if (count == 1) {
                if (num % 2 == temp0)
                    break;
                temp1 = num % 2;
            } else if (count % 2 == 0) {
                if (num % 2 != temp0) {
                    break;
                }
            } else {
                if (num % 2 != temp1) {
                    break;
                }
            }
            num /= 2;
            count++;
        }
        if (num > 0) {
            return false;
        } else {
            return true;
        }
    }
};