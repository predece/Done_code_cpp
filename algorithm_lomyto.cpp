#include <iostream>

using namespace std;

void lomuto(int* a, size_t size, int low, int high) {
	if (low >= high) {
		return;
	}
	int pivot_i = low + (high - low) / 2;
	int pivot = a[pivot_i];
	swap(a[pivot_i], a[high]);

	int i = low;
	for (int j = low; j < high; j++) {
		if (a[j] < pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[high]);
	pivot_i = i;
	lomuto(a, size, low, pivot_i - 1);
	lomuto(a, size, pivot_i + 1, high);
}

int main() {
	int a[] = { 1, 3, 4, 2 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	int low = 0;
	int high = size_a;

	lomuto(a, size_a, low, high - 1);

	for (int i = 0; i < size_a; i++) cout << a[i];

	return 0;
}