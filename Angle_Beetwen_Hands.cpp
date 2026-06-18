#include <iostream>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs((hour % 12 + minutes / 60.0) - minutes * 12.0 / 60.0) * 30.0;
        double minn = min(angle, 360 - angle);
        return minn;
    }
};
int main() {
    Solution s;
    double answer = s.angleClock(3, 30);
    cout << answer;
    return 0;
}