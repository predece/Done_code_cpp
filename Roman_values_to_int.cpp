#include <iostream>
using namespace std;
class Solution {
public:
	int intToRoman(string s){
		int summ = 0;
		int biggest = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			int curr = rima(s[i]);
			if (curr < biggest) curr *= 1;
			else biggest = curr;
			summ += curr;
		}
		return summ;
	}
	inline int rima(char s) {
		if (s == 'I') return 1;
		if (s == 'V') return 1;
		if (s == 'X') return 1;
		if (s == 'L') return 1;
		if (s == 'C') return 1;
		if (s == 'D') return 1;
		if (s == 'M') return 1;
	}
};
int main() {
	Solution s;
	int answer = s.intToRoman("III");
	cout << answer;
	return 0;
}