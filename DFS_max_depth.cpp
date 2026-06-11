#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> transformGraph_adjList(vector<vector<int>> a){
	int maxx = 0;
	for (const auto& edge : a) {
		maxx = max({ maxx, edge[0], edge[1] });
	}
	vector<vector<int>> b(maxx);
	for (auto& edge : a) {
		b[edge[0] - 1].push_back(edge[1] - 1);
		b[edge[1] - 1].push_back(edge[0] - 1);
	}
	return b;
}

int DFS(vector<vector<int>>& b, vector<bool>& visit, int i = 0, int *tow = 0, int *maxx = 0) {
	visit[i] = true;

	for (const auto& a : b[i]) {
		if (!visit[a]) {
			(*tow)++;
			DFS(b, visit, a, tow, maxx);
			if (*tow > *maxx) *maxx = *tow;
			(*tow)--;
		}
	}
	return *tow;
}

int main() {
	int maxx = 0;
	int tow = 0;
	vector<vector<int>> a = { {1, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 6}, {6, 7} };
	vector<vector<int>> b = transformGraph_adjList(a);
	vector<bool> visit(b.size(), false);
	DFS(b, visit, 0, &tow, &maxx);
	cout << maxx;
	return 0;
}