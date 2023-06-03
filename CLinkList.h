#pragma once

// 初始化循环单链表
bool init_CLinkList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}
// 循环单链表的遍历
void traversal_CLinkList(LinkList L) {
	LNode* lnode = L->next;
	while (lnode != L) {
		printf("%d\n", lnode->data);
		lnode = lnode->next;
	}
}
// 初始化循环双链表
bool init_CDLinkList(DLinkList& DL) {
	DL = (DNode*)malloc(sizeof(DNode));
	if (DL == NULL)
		return false;
	DL->prior = DL;
	DL->next = DL;
	return true;
}
// 循环双链表的遍历
void traversal_CDLinkList(DLinkList DL) {
	// 循环双链表的后向遍历
	DNode* dnode = DL->next;
	while (dnode->next != DL) {
		printf("%d\n", dnode->data);
		dnode = dnode->next;
	}
	printf("%d\n", dnode->data);// 输出最后一个结点data
	// 循环双链表的前向遍历
	while (dnode != DL) {
		printf("%d\n", dnode->data);
		dnode = dnode->prior;
	}
}