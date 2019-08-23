#pragma once

//静态顺序表

typedef struct Stack {
	int array[100];
	int size;
} Stack;

typedef int STDataType; 
typedef struct Stack {
	STDataType* _a;
	int _top; // 栈顶
	int _capacity;  // 容量
}Stack;

//初始化
void StackInit(Stack* s) {
	s->size = 0;
}

//销毁
void StackDestory(Stack* s, int v) {
	s->size = 0;
}

//插入
void StackPush(Stack* s,int v) {
	s->array[s->size++] = v;
}

//删除
void StackPop(Stack* s,int v) {
	s->size--;
}

//返回栈顶的数据，不需要删除栈顶的数据
int StsckTop(Stack* s) {
	return s->array[s->size - 1];
}

//返回栈内数据个数
int StackSize(Stack* s) {
	return s->size;
}

//返回栈内是否为空栈
//返回0：代表不是空；返回非0：表示为空
int StackEmpty(Stack* s) {
	return !s->size;
}


//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack_ch;
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			char ch = s[i];
			switch (ch) {
			case '(':
			case '[':
			case '{':
				stack_ch.push(ch);
				break;
			case ')':
			case ']':
			case '}': {
				if (stack_ch.empty()) {
					return false;
				}

				char left = stack_ch.top();
				if (!((left = '('&&ch == ')')
					|| (left == '['&&ch == ']')
					|| (left == '{'&&ch == '}'))) {
					return false;
				}
				stack_ch.pop();
				break;
			}
				  defult:
					  break;
			}
		}
		if (!stack_ch.empty()) {
			return false;
		}
		else {
			return true;
		}
	}

};






