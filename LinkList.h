#pragma once
// 单链表
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// 单链表的建立（带头结点）
bool init_List(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}
// 单链表的遍历
void traversal_List(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%d\n", L->data);
		L = L->next;
	}
}
// 单链表的插入指定位置
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
// 单链表的后插指定结点
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
// 单链表的前插指定结点
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
// 单链表的头插建立
void insert_head_List(LinkList& L) {
	int elem;
	while (scanf("%d", &elem))// 输入数字以外字符表示结束
		insert_next_List(L, L, elem);
}
// 单链表的尾插建立
void insert_tail_List(LinkList& L) {
	int elem;
	LNode* node = L;//当前结点
	while (node->next != NULL)
		node = node->next;
	while (scanf("%d", &elem)) {
		insert_next_List(L, node, elem);
		node = node->next;
	}
}
// 单链表的删除指定位置
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
// 单链表的删除指定结点
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
// 单链表的查找指定位置
// index不能大于链表长度
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
