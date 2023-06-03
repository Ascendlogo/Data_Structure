#pragma once
typedef struct {
	int data;
	int next;//��һ�������±�
}SLinkList;
// ��̬����ĳ�ʼ��
bool init_SLinkList(SLinkList* SL) {
	SL[0].next = -1;//ͷ���nextΪ-1��ʾ�ձ�
	for (int i = 1; i < MaxSize; i++) {
		SL[i].next = -2;//nextΪ-2��ʾ����
	}
	return true;
}
// ��̬����ı���
void traversal_SLinkList(SLinkList* SL) {
	int index = SL[0].next;
	while (index != -1) {
		printf("%d\n", SL[index].data);
		index = SL[index].next;
	}
}
// ��̬����Ĳ���
bool insert_SLinkList(SLinkList* SL, int elem) {
	for (int i = 1; i < MaxSize; i++) {
		if (SL[i].next == -2) {
			int index = 0;
			while (SL[index].next != -1) {
				index = SL[index].next;
			}
			SL[index].next = i;
			SL[i].data = elem;
			SL[i].next = -1;
			return true;
		}
	}
	return false;
}
// ��̬�����ɾ�� 
bool delete_SLinkList(SLinkList* SL, int i) {
	int index = 0;
	if (i < 1 || SL[i].next == -2)
		return false;
	while (SL[index].next != -1 && SL[index].next != i) {
		index = SL[index].next;
	}
	if (SL[index].next == -1)
		return false;
	SL[index].next = SL[i].next;
	SL[i].next = -2;
	return true;
}