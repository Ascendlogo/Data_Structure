#pragma once
#include<malloc.h>

// 动态顺序表：free/malloc
typedef struct {
	int* data;
	int Maxsize;
	int length;
}SeqList;

// 增加、减少动态顺序表长度
void resize_SeqList(SeqList& seql, int newSize) {
	int* p = seql.data;
	seql.data = (int*)malloc((newSize) * sizeof(int));
	for (int i = 0; i < seql.length; i++) {
		seql.data[i] = p[i];
	}
	seql.Maxsize = newSize;
}
// 动态顺序表的遍历
void traversal_SeqList(SeqList seql) {
	for (int i = 0; i < seql.length; i++) {
		printf("%d\n", seql.data[i]);
	}
}

// 动态顺序表的插入
bool insert_SeqList(SeqList& seql, int index, int elem) {
	if (index < 1 || index > seql.length + 1 || seql.length >= seql.Maxsize)
		return false;
	for (int i = seql.length - 1; i >= index - 1; i--) {
		seql.data[i + 1] = seql.data[i];
	}
	seql.data[index - 1] = elem;
	seql.length++;
	return true;
}
// 动态顺序表的删除
bool delete_SeqList(SeqList& seql, int index, int& elem) {
	if (index < 1 || index > seql.length)
		return false;
	elem = seql.data[index - 1];
	for (int i = index - 1; i < seql.length - 1; i++) {
		seql.data[i] = seql.data[i + 1];
	}
	seql.length--;
	return true;
}
// 动态顺序表的查找
// index不能大于动态顺序表长度
int find_SeqList(SeqList seql, int index) {
	return seql.data[index - 1];
}