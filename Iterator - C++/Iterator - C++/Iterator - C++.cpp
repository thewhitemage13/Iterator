#include <iostream>
using namespace std;

class DataStack {
private:
	int items[10];
	int length;
public:
	friend class StackIterator;
	DataStack() {
		length = -1;
	}
	void Push(int value) {
		items[++length] = value;
	}
	int Pop() {
		return items[length--];
	}
};

class StackIterator {
private:
	const DataStack& stack;
	int index;
public:
	StackIterator(const DataStack& st) : stack(st) {
		index = 0;
	}
	void operator++() {
		index++;
	}
	int operator*() {
		return stack.items[index];
	}
	bool operator()() {
		return index != stack.length + 1;
	}
};

bool operator == (const DataStack& s1, const DataStack& s2) {
	StackIterator it1(s1), it2(s2);

	for (; it1(); ++it1, ++it2) {
		if (*it1 != *it2) break;
	}
	return !it1() && !it2();
}

int main() {
	DataStack stack1;
	for (int i = 1; i < 5; i++)
		stack1.Push(i);

	DataStack stack2(stack1);
	cout << boolalpha << (stack1 == stack2) << "\n";
	stack1.Push(10);
	cout << boolalpha << (stack1 == stack2) << "\n";
}