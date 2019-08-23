#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main() {
	//栈是容器，要存数据，存的是int类型的数据

	std::stack<int> s;

	s.push(1);
	s.pop();
	int v = s.top();
	int size = s.size();
	s.empty();
}