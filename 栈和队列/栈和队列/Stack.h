#pragma once

//��̬˳���

typedef struct Stack {
	int array[100];
	int size;
} Stack;

typedef int STDataType; 
typedef struct Stack {
	STDataType* _a;
	int _top; // ջ��
	int _capacity;  // ����
}Stack;

//��ʼ��
void StackInit(Stack* s) {
	s->size = 0;
}

//����
void StackDestory(Stack* s, int v) {
	s->size = 0;
}

//����
void StackPush(Stack* s,int v) {
	s->array[s->size++] = v;
}

//ɾ��
void StackPop(Stack* s,int v) {
	s->size--;
}

//����ջ�������ݣ�����Ҫɾ��ջ��������
int StsckTop(Stack* s) {
	return s->array[s->size - 1];
}

//����ջ�����ݸ���
int StackSize(Stack* s) {
	return s->size;
}

//����ջ���Ƿ�Ϊ��ջ
//����0�������ǿգ����ط�0����ʾΪ��
int StackEmpty(Stack* s) {
	return !s->size;
}


//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����

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






