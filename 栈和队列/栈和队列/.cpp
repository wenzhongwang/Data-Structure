#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main() {
	//ջ��������Ҫ�����ݣ������int���͵�����

	std::stack<int> s;

	s.push(1);
	s.pop();
	int v = s.top();
	int size = s.size();
	s.empty();
}