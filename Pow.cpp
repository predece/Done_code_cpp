#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        int s = 1;
        if (x <= 0 && n % 2 != 0) s *= -1;
        if (x <= 0) x *= -1;
        double result = exp(n * log(x));
        return s*result;
    }
};
int main() {
    Solution s;
    double answer = s.myPow(2, 10);
    cout << answer;
    return 0;
}