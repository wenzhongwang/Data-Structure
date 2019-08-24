#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
};

//��������ǰ�����
void PreorderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d", root->value);
	if (root->left != NULL) {
		PreorderTraversal(root->left);
	}
	else {
		PreorderTraversal(root->right);
	}
}

//���������������
void InorderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}

	InorderTraversal(root->left);
	printf("%d", root->value);
	InorderTraversal(root->right);
}

void PostorderTraversal(Node* root) {
	if (root = NULL) {
		return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->left);
	printf("%d", root->value);
}

//ͨ�������ķ�ʽ,ǰ�к�ÿ�ξ���һ���ǿս�㣬����ciunt++
int Size(Node* root) {
	if (root == NULL) {
		return;
	}
	size++;
	Size(root->left);
	Size(root->right);

}

//���Ƶķ�ʽ
int Size2(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = Size2(root->left);
	int right = Size2(root->right);

	return left + right + 1;
}

//���Ƶķ�ʽ��Ҷ�ӽڵ�ĸ���
int LeafSize(Node* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	int left = LeafSize(root->left);
	int right = LeafSize(root->right);
	return left + right;
}

//int Max(int left, int right) {
//	if (left >= right) {
//		return left;
//	}
//	else
//		return right;
//}


//�����ĸ߶�
int GetHight(Node* root) {
	if (root = NULL) {
		return 0;
	}
	if (root->left == NULL || root->right == NULL) {
		return 1;
	}
	int left = GetHight(root->left);
	int right = GetHight(root->right);
	
	return (left > right ? left:left) + 1;

}

//���k��ڵ����
int GetKLevel(Node* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {		//root != NULL
		return 1;
	}

	int left = GetKLevel(root->left,k-1);
	int right = GetKLevel(root->right,k-1);
	return left + right;
}

//�������Ľڵ��е�value�����ظ�
//�ҽڵ��value��v�Ľ��
//�ҵ��˷���v���ڵĽ�㣻û�ҵ����� NULL
Node* Find(Node* root, int v) {
	if (root == NULL) {
		return NULL;
	}
	if (root->value == v) {
		return root;
	}
	//����������
	Node* result = Find(root->left, v);
	if (result != NULL) {
		//�������ҵ���
		return result;
	}
	result = Find(root->right, v);
	if (result != NULL) {
		return result;
	}
	else
		return NULL;

}


//����������Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p == NULL || q == NULL) {
		return false;
	}
	return p->val == q->val 
		&& isSameTree(p->left, q->left) 
		&& isSameTree(p->right, q->right);
}

//�ж��������Ƿ�Գ�
bool isMirror(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p == NULL || q == NULL) {
		return false;
	}
	return p->val == q->val
		&& isSameTree(p->left, q->right)
		&& isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
	if(root == NULL){
		return true;
	}
	return isMirror(root->left, root->right);
}

//�ж�һ�����Ƿ�Ϊ��һ����������
class Solution {
public:
	//�ж������Ƿ���ͬ
	bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		}
		if (p == NULL || q == NULL) {
			return false;
		}
		return p->val == q->val
			&& isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}

	//r�������s��ÿһ���ǿսڵ�
	bool preorder(struct TreeNode* r, struct TreeNode * t) {
		if (r == NULL) {
			return false;
		}
		//��
		if (isSameTree(r, t)) {
			return true;
		}
		//������
		bool result = preorder(r->left, t);
		if (result == true) {
			return true;
		}
		//������
		return preorder(r->right, t);
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		return preorder(s, t);
	}
};

//ƽ�������
//  &&��������ƽ�������
//	&&��������ƽ�������
//	������ƽ�������		




#if 0
//����ǰ���������һ��������
typedef struct {
	Node* root;
	int used;
} Result;

Result CreateTree(char preorder[], int size) {
	if (size == 0) {
		Result r = { NULL,0 };
		return r;
	}

	char rootValue = preorder[0];
	if (rootValue == '#') {
		Result r{ NULL,1 };
		return r;

		//��
		Node* root = (Node*)malloc(sizeof(Node));	//�����ڵ�
		root->value = rootValue;
		//������
		Result leftResult = CreateTree(preorder + 1, size - 1);
		root->left = leftResult.root; //�������õĸ��ڵ���������Ľ�㸴��
		//������
		Result rightResult = CreateTree(preorder + leftResult.used + 1, size - leftResult.used - 1);
		root->right = leftResult.root;//�������õĸ��ڵ���������Ľ�㸴��

		Result r = { root,1 + leftResult + rightResult };

		return r;
	}
}

#endif


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//���������������������

struct TreeNode* find(struct TreeNode* root, struct TreeNode* p) {
	if (root == NULL) {
		return NULL;
	}
	if (root == p) {
		return p;
	}
	struct TreeNode* result = find(root->left, p);
	if (result != NULL){
		return result;
	}
	return find(root->right, p);

}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == p || root == q) {
		return root;
	}
	struct TreeNode* pInleft = find(root->left, p);
	struct TreeNode* qInleft = find(root->left, q);

	if (pInleft != NULL && qInleft != NULL) {
		return lowestCommonAncestor(root->left, p, q);
	}
	
	if (pInleft == NULL && qInleft == NULL) {
		return lowestCommonAncestor(root->right, p, q);
	}
	return root;	//p��q��һ��һ�����������ϣ�root���Ƿ���ֵ
}


//�������Ĳ������
#include <queue>

void Levelorder(Node* root) {
	if (root == NULL) {
		printf("\n");
		return;
	}
	using std::queue;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		//ȡ����Ԫ��
		Node* front = q.front();
		q.pop();
		//���������ӡ
		printf("%d", front->value);
		//�������������
		if (front->left != NULL) {
			q.push(front->left);
		}
		//������������� 4e
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
	printf("\n");
}

//�ж�һ��������ȫ������