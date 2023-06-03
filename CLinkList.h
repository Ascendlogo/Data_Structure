#pragma once

// ��ʼ��ѭ��������
bool init_CLinkList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}
// ѭ��������ı���
void traversal_CLinkList(LinkList L) {
	LNode* lnode = L->next;
	while (lnode != L) {
		printf("%d\n", lnode->data);
		lnode = lnode->next;
	}
}
// ��ʼ��ѭ��˫����
bool init_CDLinkList(DLinkList& DL) {
	DL = (DNode*)malloc(sizeof(DNode));
	if (DL == NULL)
		return false;
	DL->prior = DL;
	DL->next = DL;
	return true;
}
// ѭ��˫����ı���
void traversal_CDLinkList(DLinkList DL) {
	// ѭ��˫����ĺ������
	DNode* dnode = DL->next;
	while (dnode->next != DL) {
		printf("%d\n", dnode->data);
		dnode = dnode->next;
	}
	printf("%d\n", dnode->data);// ������һ�����data
	// ѭ��˫�����ǰ�����
	while (dnode != DL) {
		printf("%d\n", dnode->data);
		dnode = dnode->prior;
	}
}