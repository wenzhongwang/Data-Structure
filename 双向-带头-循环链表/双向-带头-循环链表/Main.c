

typedef struct DNode {
	int value;
	struct DNode* prev;
	struct DNode* next;
} DNode;

void DListInit(DNode **node) {
	//创建头结点
	DNode *head = (DNode*)malloc(sizeof(DNode));
	//head->value没有用
	head->next = head;
	head->prev = head;

	*node = head;
}

//头插
void DListPushFront(DNode *head, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

//尾插
void DListPushBack(DNode *head, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = head->prev;
	node->next = head;
	head->prev->next = node;
	head->prev = node;
}

//pos后面做插入
void DListInsertAfter(DNode* head, DNode* pos, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

//pos前面做插入
void DListInsertBefore(DNode* head, DNode* pos, int v) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;
	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}



void Test() {
	DNode* node;  //新节点
	DListInit(&node);  //初始化
	//node会变成头结点的地址
}

int main() {
	Test();
	return 0;
}