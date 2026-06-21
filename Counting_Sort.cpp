#include <iostream>
#include <vector>
using namespace std;
vector<int> countSort(vector<int>& Data) {
	int maxx = 0;
	vector<int> ans(Data.size());

	for (int i = 0; i < Data.size(); i++) {
		maxx = max(maxx, Data[i]);
	}

	vector<int> new_data(maxx + 1, 0);

	for (int i = 0; i < Data.size(); i++) {
		new_data[Data[i]]++;
	}

	for (int i = 1; i < new_data.size(); i++) {
		new_data[i] += new_data[i - 1];
	}

	//Reversed Используется для объектов, где важен порядок
	for (int i = Data.size() - 1; i >= 0; i--) {
		ans[new_data[Data[i]] - 1] = Data[i];
		new_data[Data[i]]--;
	}

	//Forward
	for (int i = 0; i < Data.size(); i++) {
		ans[new_data[Data[i]] - 1] = Data[i];
		new_data[Data[i]]--;
	}

	return ans;
}

int main() {
	vector<int> data = { 9, 0, 1, 1, 2, 5, 4 };
	vector<int> answer = countSort(data);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}