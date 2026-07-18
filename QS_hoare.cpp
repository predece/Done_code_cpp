#include <iostream>

using namespace std;

int partition(int* arr, int LEFT, int RIGHT) {
	int pivot = arr[(RIGHT + LEFT) / 2];
	int i = LEFT;
	int j = RIGHT;
	while (true) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i >= j) return j;
		swap(arr[i++], arr[j--]);
	}
}

void QS_hoare(int* arr, int LEFT, int RIGHT) {
	if (LEFT < RIGHT) {
		int p = partition(arr, LEFT, RIGHT);
		QS_hoare(arr, LEFT, p);
		QS_hoare(arr, p+1, RIGHT);
	}
}

int main() {
	int arr[] = { 9, 3, 2, 1, 6, 3, 4, 5, 6, 7 };
	QS_hoare(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (int& s : arr) cout << s << " ";
	return 0;
}

