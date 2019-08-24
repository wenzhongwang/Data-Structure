

typedef struct DNode {
	int value;
	struct DNode* prev;
	struct DNode* next;
} DNode;

void DListInit(DNode **node) {
	//����ͷ���
	DNode *head = (DNode*)malloc(sizeof(DNode));
	//head->valueû����
	head->next = head;
	head->prev = head;

	*node = head;
}

//ͷ��
void DListPushFront(DNode *head, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

//β��
void DListPushBack(DNode *head, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = head->prev;
	node->next = head;
	head->prev->next = node;
	head->prev = node;
}

//pos����������
void DListInsertAfter(DNode* head, DNode* pos, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

//posǰ��������
void DListInsertBefore(DNode* head, DNode* pos, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}



void Test() {
	DNode* node;  //�½ڵ�
	DListInit(&node);  //��ʼ��
	//node����ͷ���ĵ�ַ
}

int main() {
	Test();
	return 0;
}