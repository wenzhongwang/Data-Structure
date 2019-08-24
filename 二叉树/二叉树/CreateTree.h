#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <assert.h>
#include <stack>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char value;
}  Node;

typedef struct {
	Node* node;  //�������������ڵ�
	int used;    //����������ʹ�õ����г���
} Result;


//����������
Result CreateTree(const char preorder[], int size) {
	Result result;
	if (size == 0) {
		result.node = NULL;
		result.used = 0;
		return result;
	}

	if (preorder[0] == '#') {
		result.node = NULL;
		result.used = 1;
		return result;
	}
	//��
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = preorder[0];
	//������
	Result leftR = CreateTree(preorder + 1, size - 1);
	//������
	Result rightR = CreateTree(preorder + leftR.used + 1, size - leftR.used - 1);

	root->left = leftR.node;  //rootΪA�ǣ� BΪ����һ����
	root->right = rightR.node;  //CΪ����һ����

	result.node = root;
	result.used = leftR.used + rightR.used + 1;
	return result;
}


//
//�������
void Levelorder(Node* root) {
	if (root == NULL) {
		printf("\n");
		return;
	}
	using std::queue;
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		printf("%c ", front->value);

		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	
	}

	printf("\n");
}


//�Ƿ�Ϊ��ȫ������
bool isComplete(Node* root) {
	if (root = NULL) {
		return true;
	}

	using std::queue;
	queue<Node*> q;
	q.push(root);  //�����

	while (true) {
		Node* front = q.front();  //ȡ����Ԫ��
		q.pop(); //������
		if (front == NULL) {
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		if (front != NULL) {
			return false;
		}
	}
	return true;
}


void Test() {
	const char *preorder = "ABD##E#H##CF##G";
	int size = strlen(preorder);
	Result result = CreateTree(preorder, size);

	Levelorder(result.node);
}



//����ǰ��ͺ��򹹼ܶ�����
Node* buildTree(const char preorder[],const char inorder[], int size) {
	if (size == 0) {
		return NULL;
	}
	char rootValue = preorder[0];
	int r = -1;
	for (int i = 0; i < size; ++i) {
		if (inorder[i] == rootValue) {
			r = i;
			break;
		}
	}
	assert(r != -1);

	Node* root = (Node*)malloc(sizeof(Node));
	root->value = rootValue;

	//������
	root->left = buildTree(preorder + 1, inorder, r);  //ǰ���У�r
	//������
	//������+1+r
	root->right = buildTree(preorder + 1 + r,inorder + r + 1, size - 1 - r);
	
	return root;
}


//��������ͺ��򹹽�������
Node* buildTree2(char inorder[],char postorder[], int size) {
	if (size == 0) {
		return NULL;
	}

	int r = -1;
	for (int i = 0; i < size; ++i) {
		r = i;
		break;
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = postorder[size - 1];
	//������ ->���򡢺���
	root->left = buildTree2(inorder, postorder, r);
	//������->���򡢺���
	root->right = buildTree2(inorder + r + 1, postorder + r, size - 1 - r);

	return root;
}

void Test3() {
	char* inorder = "DBEHAFCD";
	char* preorder = "ABDEHCFG";
	int size = strlen(preorder);

	Node* root = buildTree2(inorder, preorder, size);

	Levelorder(root);
}



//�ǵݹ�ǰ�����

using std::stack;

void PreorderNoR(Node* root) {
	stack<Node*> s;
	Node* cur = root;

	while (cur != NULL && !s.empty()) {
		while (cur != NULL) {
			printf("%c", cur->value);
			s.push(cur);
			cur = cur->left;
		}

		Node* top = s.top();
		s.pop();

		cur = top->left;
	}
	printf("\n");
}

void Test4() {
	char* preorder = "ABDEHCFG";
	char* inorder = "DBEHAFCD";
	int size = strlen(preorder);

	Node* root = buildTree2(inorder, preorder, size);

	Levelorder(root);
	PreorderNoR(root);
}



