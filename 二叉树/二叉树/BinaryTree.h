#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
};

//二叉树的前序遍历
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

//二叉树的中序遍历
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

//通过遍历的方式,前中后，每次经过一个非空结点，计算ciunt++
int Size(Node* root) {
	if (root == NULL) {
		return;
	}
	size++;
	Size(root->left);
	Size(root->right);

}

//递推的方式
int Size2(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = Size2(root->left);
	int right = Size2(root->right);

	return left + right + 1;
}

//递推的方式求叶子节点的个数
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


//求树的高度
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

//求第k层节点个数
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

//二叉树的节点中的value都不重复
//找节点的value是v的结点
//找到了返回v所在的结点；没找到返回 NULL
Node* Find(Node* root, int v) {
	if (root == NULL) {
		return NULL;
	}
	if (root->value == v) {
		return root;
	}
	//左子树中找
	Node* result = Find(root->left, v);
	if (result != NULL) {
		//左子树找到了
		return result;
	}
	result = Find(root->right, v);
	if (result != NULL) {
		return result;
	}
	else
		return NULL;

}


//检查两个树是否相同
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

//判断两个树是否对称
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

//判断一个树是否为另一个树的子树
class Solution {
public:
	//判断两树是否相同
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

	//r代表的是s的每一个非空节点
	bool preorder(struct TreeNode* r, struct TreeNode * t) {
		if (r == NULL) {
			return false;
		}
		//根
		if (isSameTree(r, t)) {
			return true;
		}
		//左子树
		bool result = preorder(r->left, t);
		if (result == true) {
			return true;
		}
		//右子树
		return preorder(r->right, t);
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		return preorder(s, t);
	}
};

//平衡二叉树
//  &&左子树是平衡二叉树
//	&&右子树是平衡二叉树
//	空树是平衡二叉树		




#if 0
//根据前序遍历创建一个二叉树
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

		//根
		Node* root = (Node*)malloc(sizeof(Node));	//创建节点
		root->value = rootValue;
		//左子树
		Result leftResult = CreateTree(preorder + 1, size - 1);
		root->left = leftResult.root; //给创建好的根节点的左子树的结点复制
		//右子树
		Result rightResult = CreateTree(preorder + leftResult.used + 1, size - leftResult.used - 1);
		root->right = leftResult.root;//给创建好的根节点的右子树的结点复制

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

//找两个树的最近公共祖先

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
	return root;	//p和q在一左一右两个子树上，root就是返回值
}


//二叉树的层序遍历
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
		//取队首元素
		Node* front = q.front();
		q.pop();
		//层序遍历打印
		printf("%d", front->value);
		//插入左子树结点
		if (front->left != NULL) {
			q.push(front->left);
		}
		//插入右子树结点 4e
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
	printf("\n");
}

//判断一棵树是完全二叉树