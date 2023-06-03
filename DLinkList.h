#pragma once
// 双链表应从头结点出发至尾结点，再从尾结点出发至头结点。所有结点都在头结点之后，尾结点的下一个节点为NULL。

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
}DNode, * DLinkList;
// 双链表的初始化
bool init_DLinkList(DLinkList& DL) {
    DL = (DNode*)malloc(sizeof(DNode));
    if (DL == NULL)
        return false;
    DL->next = NULL;
    DL->prior = NULL;
    return true;
}
// 双链表的遍历
void traversal_DLinkList(DLinkList DL) {
    // 双链表的后向遍历
    DNode* dnode = DL->next;
    while (dnode->next != NULL) {
        printf("%d\n", dnode->data);
        dnode = dnode->next;
    }
    printf("%d\n", dnode->data);// 输出最后一个结点data
    // 双链表的前向遍历
    while (dnode->prior != NULL) {
        printf("%d\n", dnode->data);
        dnode = dnode->prior;
    }
}
// 双链表的后插
// 将insert_node结点插入dnode结点之后
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
// 双链表的前插
// 将insert_node结点插入dnode结点之前
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
// 双链表的后继结点删除
// 删除dnode结点后继结点
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
// 双链表的前继结点删除
// 删除dnode结点前继结点
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
// 双向链表的建立
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