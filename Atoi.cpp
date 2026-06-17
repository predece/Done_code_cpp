#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int znak = 1;
        bool stat = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '-') {
				if (stat) {
					break;
				}
                znak = -1;
                stat = 1;
                continue; 
            }
            if (s[i] == '+') {
                if (stat) {
                    break;
                }
                stat = 1;
                continue;
            }
            if (!stat && s[i] == '0') {
                stat = 1;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                stat = 1;  
                if (znak * result > INT_MAX / 10 || (znak * result == INT_MAX / 10 && (s[i] - '0') >= (INT_MAX % 10))) return (INT_MAX);
                if (znak * result < INT_MIN / 10 || (znak * result == INT_MIN / 10 && znak*(s[i] - '0') <= (INT_MIN % 10))) return INT_MIN;
                result = result * 10 + (s[i] - '0');
                continue;
            }
            else if (stat) {
				break;
            }
            break;
        }
        return result*znak;
    }
};

int main() {
  Solution s;
	int answer = s.myAtoi("2147483646");
  cout << answer;
  return 0;
}