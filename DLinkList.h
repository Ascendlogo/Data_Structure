#pragma once
// ˫����Ӧ��ͷ��������β��㣬�ٴ�β��������ͷ��㡣���н�㶼��ͷ���֮��β������һ���ڵ�ΪNULL��

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;
// ˫����ĳ�ʼ��
bool init_DLinkList(DLinkList& DL) {
    DL = (DNode*)malloc(sizeof(DNode));
    if (DL == NULL)
        return false;
    DL->next = NULL;
    DL->prior = NULL;
    return true;
}
// ˫����ı���
void traversal_DLinkList(DLinkList DL) {
    // ˫����ĺ������
    DNode* dnode = DL->next;
    while (dnode->next != NULL) {
        printf("%d\n", dnode->data);
        dnode = dnode->next;
    }
    printf("%d\n", dnode->data);// ������һ�����data
    // ˫�����ǰ�����
    while (dnode->prior != NULL) {
        printf("%d\n", dnode->data);
        dnode = dnode->prior;
    }
}
// ˫����ĺ��
// ��insert_node������dnode���֮��
bool insert_next_DLinkList(DNode* dnode, DNode* insert_node) {
    if (dnode == NULL || insert_node == NULL)
        return false;
    insert_node->next = dnode->next;
    if (dnode->next != NULL)
        dnode->next->prior = insert_node;
    insert_node->prior = dnode;
    dnode->next = insert_node;
    return true;
}
// ˫�����ǰ��
// ��insert_node������dnode���֮ǰ
bool insert_prior_DLinkList(DNode* dnode, DNode* insert_node) {
    if (dnode == NULL || insert_node == NULL)
        return false;
    insert_node->prior = dnode->prior;
    if (dnode->prior != NULL)
        dnode->prior->next = insert_node;
    insert_node->next = dnode;
    dnode->prior = insert_node;
    return true;
}
// ˫����ĺ�̽��ɾ��
// ɾ��dnode����̽��
bool delete_next_DLinkList(DNode* dnode) {
    if (dnode == NULL || dnode->next == NULL)
        return false;
    DNode* delete_node = dnode->next;
    dnode->next = delete_node->next;
    if (delete_node->next != NULL)
        delete_node->next->prior = dnode;
    free(delete_node);
    return true;
}
// ˫�����ǰ�̽��ɾ��
// ɾ��dnode���ǰ�̽��
bool delete_prior_DLinkList(DNode* dnode) {
    if (dnode == NULL || dnode->prior == NULL)
        return false;
    DNode* delete_node = dnode->prior;
    dnode->prior = delete_node->prior;
    if (delete_node->prior != NULL)
        delete_node->prior->next = dnode;
    free(delete_node);
    return true;
}
// ˫������Ľ���
bool insert_head_DLinklist(DLinkList DL) {
    int elem;
    DNode* temp_dnode = DL;
    while (scanf("%d", &elem)) {
        DNode* dnode = (DNode*)malloc(sizeof(DNode));
        if (dnode == NULL)
            return false;
        dnode->data = elem;
        insert_next_DLinkList(temp_dnode, dnode);
        temp_dnode = dnode;
    }
    return true;
}