#pragma once
// ������
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// ������Ľ�������ͷ��㣩
bool init_List(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}
// ������ı���
void traversal_List(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%d\n", L->data);
		L = L->next;
	}
}
// ������Ĳ���ָ��λ��
bool insert_List(LinkList& L, int index, int elem) {
	if (index < 1)
		return false;
	int j = 0;
	LNode* node;
	node = L;
	while (node != NULL && j < index - 1) {
		node = node->next;
		j++;
	}
	if (node == NULL)
		return false;
	LNode* insert_node = (LNode*)malloc(sizeof(LNode));
	if (insert_node == NULL)
		return false;
	insert_node->data = elem;
	insert_node->next = node->next;
	node->next = insert_node;
	return true;
}
// ������ĺ��ָ�����
bool insert_next_List(LinkList L, LNode* node, int elem) {
	if (node == NULL)
		return false;
	LNode* insert_node = (LNode*)malloc(sizeof(LNode*));
	if (insert_List == NULL)
		return false;
	insert_node->data = elem;
	insert_node->next = node->next;
	node->next = insert_node;
	return true;
}
// �������ǰ��ָ�����
bool insert_prior_List(LinkList L, LNode* node, int elem) {
	if (node == NULL || node == L)
		return false;
	LNode* insert_node = (LNode*)malloc(sizeof(LNode*));
	if (insert_List == NULL)
		return false;
	insert_node->next = node->next;
	node->next = insert_node;
	insert_node->data = node->data;
	node->data = elem;
	return true;
}
// �������ͷ�彨��
void insert_head_List(LinkList& L) {
	int elem;
	while (scanf("%d", &elem))// �������������ַ���ʾ����
		insert_next_List(L, L, elem);
}
// �������β�彨��
void insert_tail_List(LinkList& L) {
	int elem;
	LNode* node = L;//��ǰ���
	while (node->next != NULL)
		node = node->next;
	while (scanf("%d", &elem)) {
		insert_next_List(L, node, elem);
		node = node->next;
	}
}
// �������ɾ��ָ��λ��
bool delete_index_List(LinkList L, int index, int& elem) {
	if (index < 1)
		return false;
	int j = 0;
	LNode* node = L;
	while (node != NULL && j < index - 1) {
		node = node->next;
		j++;
	}
	if (node == NULL)
		return false;
	elem = node->next->data;
	LNode* delete_node = node->next;
	node->next = delete_node->next;
	free(delete_node);
}
// �������ɾ��ָ�����
bool delete_node_List(LinkList L, LNode* delete_node) {
	if (delete_node == NULL)
		return false;
	if (delete_node->next != NULL) {
		LNode* temp_node = delete_node->next;
		delete_node->data = temp_node->data;
		delete_node->next = temp_node->next;
		free(temp_node);
	}
	else {
		LNode* node = L;
		while (node->next->next != NULL)
			node = node->next;
		node->next = NULL;
		free(delete_node);
	}
	return true;
}
// ������Ĳ���ָ��λ��
// index���ܴ���������
LNode* find_index_List(LinkList L, int index) {
	if (index < 0)
		return NULL;
	LNode* node = L;
	int j = 0;
	while (L != NULL && j < index) {
		node = node->next;
		j++;
	}
	return node;
}
