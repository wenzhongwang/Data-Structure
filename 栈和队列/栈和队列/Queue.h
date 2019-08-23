#pragma once
#include <stdio.h>
#include <stdlib.h>


//����ڵ�Ľṹ��
typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Queue {
	Node* head;  //����ĵ�һ���ڵ�
	Node* last;  //��������һ�����
} Queue;

//��ʼ��
void QueueInit(Queue* q) {
	q->head = q->last = NULL;
}

void QueueDestroy(Queue* q) {
	Node *cur, *next;
	for (cur = q->head; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	q->head = q->last = NULL;
}

//β��
void QueuePush(Queue* q,int v){ 
	Node* node= (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (q->head == NULL) {
		q->head = node;
		q->last = node;
	}
	else {
		q->last->next = node;
		q->last = node;
	}
}

//ͷɾ
void QueuePop(Queue* q) {
	Node* second = q->head->next;
	free(q->head);
	q->head = second;

	//lastҲ�п�����Ҫ���
	if (q->head == NULL) {
		q->head == NULL;
	}
}

//���ض�����Ԫ��
int QueueFront(Queue* q) {
	return q->head->value;
}

//���ض��д�С
int  QueueSize(Queue* q) {
	int size = 0;
	for (Node* cur = q->head; cur != NULL; cur = cur->next) {
		size++;
	}
	return size;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* q) {
	if (q->head == NULL) {
		return -1;
	}
	else {
		return 0;
	}
}
