#pragma once
#include <stdio.h>
#include <stdlib.h>


//链表节点的结构体
typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Queue {
	Node* head;  //链表的第一个节点
	Node* last;  //链表的最后一个结点
} Queue;

//初始化
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

//尾插
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

//头删
void QueuePop(Queue* q) {
	Node* second = q->head->next;
	free(q->head);
	q->head = second;

	//last也有可能需要变更
	if (q->head == NULL) {
		q->head == NULL;
	}
}

//返回队列首元素
int QueueFront(Queue* q) {
	return q->head->value;
}

//返回队列大小
int  QueueSize(Queue* q) {
	int size = 0;
	for (Node* cur = q->head; cur != NULL; cur = cur->next) {
		size++;
	}
	return size;
}

//判断队列是否为空
int QueueEmpty(Queue* q) {
	if (q->head == NULL) {
		return -1;
	}
	else {
		return 0;
	}
}
