#pragma once
// 静态顺序表：数组
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
}SqList;

// 静态顺序表的遍历
void traversal_SqList(SqList sql) {
	for (int i = 0; i < sql.length; i++) {
		printf("%d\n", sql.data[i]);
	}
}

// 静态顺序表的插入
bool insert_SqList(SqList& sql, int index, int elem) {
	if (index < 1 || index > sql.length + 1 || sql.length >= MaxSize)
		return false;
	for (int i = sql.length - 1; i >= index - 1; i--) {
		sql.data[i + 1] = sql.data[i];
	}
	sql.data[index - 1] = elem;
	sql.length++;
	return true;
}
// 静态顺序表的删除
bool delete_SqList(SqList& sql, int index, int& elem) {
	if (index < 1 || index > sql.length) {
		return false;
	}
	elem = sql.data[index - 1];
	for (int i = index - 1; i < sql.length - 1; i++) {
		sql.data[i] = sql.data[i + 1];
	}
	sql.length--;
	return true;
}
// 静态顺序表的查找
// index不能大于静态顺序表长度
int find_SqList(SqList sql, int index) {
	return sql.data[index - 1];
}