//Algoritm Фенвика
#include <iostream>
#include <vector>
using namespace std;
class Finvik {
	int size{};
	vector<int> f;
	int lowbit(int x) {
		return x & -x;
	}
public:
	Finvik(int n) : size(n) {
		f.assign(size, 0);
	}
	void add(int idx, int delta) {
		idx++;
		while (idx <= size) {
			f[idx] += delta;
			idx += lowbit(idx);
		}
	}
	int query(int idx) {
		if (idx < 0) return 0;
		int answer = 0;
		idx++;
		while (idx > 0) {
			answer += f[idx];
			idx -= lowbit(idx);
		}
		return answer;
	}
	int query_p(int idx_1, int idx_2){
		return query(idx_2) - query(idx_1);
	}
};
int main() {
	Finvik fin(10);
	vector<int> def{ 10,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++) {
		fin.add(i, def[i]);
	}
	int as = fin.query(2);
	int aq = fin.query_p(2, 3);
	cout << aq;
	return 0;
}