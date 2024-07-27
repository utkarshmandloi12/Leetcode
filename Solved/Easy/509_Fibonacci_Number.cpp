class Solution {
public:
    int fib(int n) {
        float z = sqrt(5);
        long long int t = (pow(2, n) * z);
        long long int a = (pow(1 + z, n));
        long long int b = (pow(1 - z, n));
        return (a - b) / t;
    }
};