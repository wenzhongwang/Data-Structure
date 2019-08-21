#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDateType;

//����Ĳ�������Ľṹ�壬����������һ���ڵ�Ľṹ��
typedef struct ListNode {
	SListDateType value;  //�����ֵ
	struct ListNode* next; //������һ���ڵ�ĵ�ַ
} Node;

typedef struct SList {
	Node *first;
} SList;

//��ʼ��
void SListInit(SList *s) {
	assert(s != NULL);
	s->first = NULL;
}


//����
//ͷ��
void SListPushFront(SList *s, SListDateType v) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}

//β��
void SListPushBack(SList *s, SListDateType v) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	
	//����Ϊ�յ����
	if (s->first == NULL) {
		s->first = node;
		return;
	}

	//����������һ���ڵ�����
	Node* cur = s->first;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	//cur->nextһ����NULL
	cur->next = node;
}


//ͷɾ
void SListPopFront(SList *s) {
	assert(s != NULL);          //����û������
	assert(s->first != NULL);   //����û�нڵ�

	Node* next = s->first->next;
	free(s->first);
	s->first = next;
	
}

//βɾ
void SListPopBack(SList* s) {
	assert(s != NULL);          //����û������
	assert(s->first != NULL);   //����û�нڵ�

	//�����о�һ���ڵ�
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
		//cur�ǵ����ڶ����ڵ�
	//cur->next->next=NULL;
		free(cur->next);
		cur->next = NULL;
	}
	
}

//����
Node* SListFind(SList* s, SListDateType v) {
	for (Node* cur = s->first; cur != NULL; cur = cur->next) {
		if (cur->value == v) {
			return cur;
		}
	}

	return NULL;
}

// ��pos�Ľڵ����������
void SListInsertAfter(SList* s, Node* pos, SListDateType v) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//posһ���������еĽڵ㣬����pos����SList�����һ���ڵ�

void SListEraseAfter(SList* s, Node* pos) {
	Node* next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

//����
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
		//����ΪNULL
		return;
	}
	if (s->first->value == v) {
		//v���ǵ�һ���ڵ�����
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


//1.��תһ������
//���룺1->2->3->4->5->NULL
//�����5->4->3->2->1->NULL
struct ListNode* reverseList(struct ListNode* head) {

	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* p1 = NULL;
	struct ListNode* p2 = head;
	struct ListNode* p3 = head->next;

	while (p2 != NULL) {
		p2->next = p1;

		//������
		p1 = p2;
		p2 = p3;
		if (p3 != NULL) { p3 = p3->next; }
	}
	//Ӧ����һ������
	return .....
}

//3.������м�ڵ�
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

//4.������K���ڵ�
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

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
//1->2->4, 1->3->4
//1->1->2->3->4->4
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* c1 = l1;
	struct ListNode* c2 = l2;
	struct ListNode* result = NULL;//�������ĵ�һ�����
	struct ListNode* tail = NULL;  //����������һ���ڵ�
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


//��ת������

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