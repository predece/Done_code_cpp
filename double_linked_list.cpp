#include <iostream>

using namespace std;

class my_double_link_list {
	string name;

	my_double_link_list* next;
	my_double_link_list* pred;

	static my_double_link_list* head;
	static my_double_link_list* tail;

public:
	my_double_link_list() : next(nullptr), pred(nullptr) {};
	void push_first(string name) {
		my_double_link_list* exmp = new my_double_link_list;
		exmp->name = name;
		if (!tail) {
			tail = head = exmp;
		}
		else {
			exmp->next = head;
			head->pred = exmp;
			head = exmp;
		}
	};

	void push_back(string name) {
		my_double_link_list* exmp = new my_double_link_list;
		exmp->name = name;
		if (!head) {
			tail = head = exmp;
		}
		else {
			exmp->pred = head;
			head->next = exmp;
			tail = exmp;
		}
	};
	void print_front() {
		my_double_link_list* current = head;
		cout << "Front: " << endl;
		while (current) {
			cout << "Name: " << current->name << endl;
			current = current->next;
		}
	};
	void print_back() {
		my_double_link_list* current = tail;
		cout << "Back:" << endl;
		while (current) {
			cout << "Name: " << current->name << endl;
			current = current->pred;
		}
	};

};

my_double_link_list* my_double_link_list::head = nullptr;
my_double_link_list* my_double_link_list::tail = nullptr;

int main() {
	my_double_link_list a;
	a.push_first("12");
	a.push_back("13");

	a.print_back(); 
	a.print_front();

	return 0;
}