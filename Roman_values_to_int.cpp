#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        int big = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int cur = rom(s[i]);
            if (cur < big) cur *= -1;
            else big = cur;
            answer += cur;
        }
        return answer;
    }
    inline int rom(char a) {
        if (a == 'I') return 1;
        if (a == 'V') return 5;
        if (a == 'X') return 10;
        if (a == 'L') return 50;
        if (a == 'C') return 100;
        if (a == 'D') return 500;
        if (a == 'M') return 1000;
        return 0;
    }
};

int main() {
	Solution s;
	int answer = s.romanToInt("III");
	cout << answer;
	return 0;
}