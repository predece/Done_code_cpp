#include <iostream>

using namespace std;

template<typename T>
class Binary_Search {
	T value;
	T* list;
	T value_find;
	size_t size; 
public:

	T a(T* list, int left, int right) {
		if (left > right) {
			cout << "Element not found!" << endl;
			return -1;
		}

		int si;
		int scal = right - left;

		si = left + (right - left) / 2; 

		if (list[si] == this->value) {
			return si;
		}
		if (this->value < list[si]) {
			return a(list, left, si-1);
		}
		if (this->value > list[si]) {
			return a(list, si+1, right);
		}
	}

	void bubble_sort(T* list_s) {
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (i != j) {
					if (list_s[i] > list_s[j]) {
						T a = list[i];
						list_s[i] = list_s[j];
						list_s[j] = a;
					}
				}
			}
		}

	}

	void search(T value, T* list_i, int size)  {
		this->size = size; 
		this->value = value;

		list = new T[size];
		for (int i = 0; i < size; i++) {
			list[i] = list_i[i];
		}

		bubble_sort(list);

		cout << "Start binary search:" << endl;
		cout << "Search: " << value << endl;

		T b = a(list, 0, size - 1);
		cout << "Your values find! Index: " << b << endl;

		delete[] list;
	}
};

int main() {
	Binary_Search<int> a;
	int a_l[] = {15, 12, 13, 14, 19, 20, 21};
	a.search(10, a_l, 7);


	return 0;
}