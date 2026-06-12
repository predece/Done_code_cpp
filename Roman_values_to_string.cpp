#include <iostream>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		const int value[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		const int size_v = sizeof(value) / sizeof(value[0]);
		const string symbol[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
		string result = "";
		while (num > 0) {
			for (int i = size_v - 1; i >= 0; i--) {
				if (num >= value[i]) {
					num -= value[i];
					result += symbol[i];
					break;
				}
			}
		}
		return result;
	}
};
int main() {
	Solution s;
	string answer = s.intToRoman(1994);
	cout << answer;
	return 0;
}