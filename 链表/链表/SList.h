#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDateType;

//定义的不是链表的结构体，而是链表中一个节点的结构体
typedef struct ListNode {
	SListDateType value;  //保存的值
	struct ListNode* next; //保存下一个节点的地址
} Node;

typedef struct SList {
	Node *first;
} SList;

//初始化
void SListInit(SList *s) {
	assert(s != NULL);
	s->first = NULL;
}


//插入
//头插
void SListPushFront(SList *s, SListDateType v) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}

//尾插
void SListPushBack(SList *s, SListDateType v) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	
	//链表为空的情况
	if (s->first == NULL) {
		s->first = node;
		return;
	}

	//链表至少有一个节点的情况
	Node* cur = s->first;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	//cur->next一定是NULL
	cur->next = node;
}


//头删
void SListPopFront(SList *s) {
	assert(s != NULL);          //不能没有链表
	assert(s->first != NULL);   //不能没有节点

	Node* next = s->first->next;
	free(s->first);
	s->first = next;
	
}

//尾删
void SListPopBack(SList* s) {
	assert(s != NULL);          //不能没有链表
	assert(s->first != NULL);   //不能没有节点

	//链表中就一个节点
	if (s->first->next == NULL) {
		free(s->first);
		s->first = NULL;
		return;
	}
	else {
		Node* cur = s->first;
		while (cur->next->next != NULL) {
			cur = cur->next;
		}
		//cur是倒数第二个节点
	//cur->next->next=NULL;
		free(cur->next);
		cur->next = NULL;
	}
	
}

//查找
Node* SListFind(SList* s, SListDateType v) {
	for (Node* cur = s->first; cur != NULL; cur = cur->next) {
		if (cur->value == v) {
			return cur;
		}
	}

	return NULL;
}

// 在pos的节点后面做插入
void SListInsertAfter(SList* s, Node* pos, SListDateType v) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//pos一定是链表中的节点，而且pos不是SList的最后一个节点

void SListEraseAfter(SList* s, Node* pos) {
	Node* next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

//销毁
void SListDestory(SList* s) {
	Node* next;
	for (Node* cur = s->first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	s->first = NULL;
}

void SListRemove(SList* s, SListDateType v) {
	if (s->first == NULL) {
		//链表为NULL
		return;
	}
	if (s->first->value == v) {
		//v就是第一个节点的情况
		Node* next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}

	Node* cur = s->first;
	while(cur->next != NULL) {
		if (cur->next->value == v) {
			Node* next = cur->next->next;
			free(cur->next);
			cur->next = next;
			return;
		}
		cur = cur->next;
	}
}

#if 0
void SListRemove2(SList* s, SListDataType v) {
	if (s->first == NULL) {
		return;
	}
	Node* fake = (Node*)malloc(sizeof(Node));
	fake->next = s->first;

	Node* cur = fake;
	while (cur->next != NULL) {
		if () {

		}
		cur = cur->next;
	}
	free(fake);
}
#endif


void Test() {
	SList list;
	SListInit(&list);

	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	//1 2 3
	SListPushFront(&list, 30);
	SListPushFront(&list, 20);
	SListPushFront(&list, 10);
	//10 20 30 1 2 3
	Node* pos = SListFind(&list, 30);
	SListInsertAfter(&list, pos, 100);
	//10 20 30 100 1 2 3
	SListEraseAfter(&list, pos);
	//20 30 1 2 3 
	SListPopFront(&list);
	//20 30 1 2 
	SListPopBack(&list);

	SListDestory(&list);

}


//1.反转一个链表
//输入：1->2->3->4->5->NULL
//输出：5->4->3->2->1->NULL
struct ListNode* reverseList(struct ListNode* head) {

	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* p1 = NULL;
	struct ListNode* p2 = head;
	struct ListNode* p3 = head->next;

	while (p2 != NULL) {
		p2->next = p1;

		//往后走
		p1 = p2;
		p2 = p3;
		if (p3 != NULL) { p3 = p3->next; }
	}
	//应该有一个返回
	return .....
}

//3.链表的中间节点
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
		fast = fast->next;
	
	}
	return slow;
}

//4.倒数第K个节点
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* front = pListHead;
		ListNode* back = pListHead;
		unsigned int i;
		for (i = 0; front != NULL && i < k; ++i) {
			front = front->next;
		}
		if (i < k) {
			return NULL;
		}
		while (front) {
			front = front->next;
			back = back->next;
		}
	}
};

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//1->2->4, 1->3->4
//1->1->2->3->4->4
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* c1 = l1;
	struct ListNode* c2 = l2;
	struct ListNode* result = NULL;//结果链表的第一个结点
	struct ListNode* tail = NULL;  //结果链表最后一个节点
	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			if (tail == NULL) {
				result = tail = c1;
			}
			else {
				tail->next = c1;
				tail = c1;
			}

			c1 = c1->next;
		}

		else {
			if (tail == NULL) {
				result = tail = c2;
			}
			else {
				tail->next = c2;
				tail = c2;
			}
			c2 = c2->next;
		}
	}
	if (c1 == NULL && c2 != NULL) {
		if (tail == NULL) {
			result = tail = c2;
		}
		else {
			tail->next = c2;
			tail = c2;
		}
		c2 = c2->next;
	}
	if (c2 == NULL && c1 != NULL) {
		if (tail == NULL) {
			result = tail = c1;
		}
		else {
			tail->next = c1;
			tail = c1;
		}
		c1 = c1->next;
	}

	return result;
}


//反转单链表

Node* Reverse(Node* head) {
	Node* prev = NULL;
	Node* cur = head;

	while (cur != NULL) {
		Node* next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}