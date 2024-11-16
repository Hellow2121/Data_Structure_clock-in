#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#define MaxSize 10   //定义最大长度

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];   //用静态数组存放数据元素
	int length;               //顺序表的当前长度
}SqList;                      //顺序表的类型定义

//初始化一个顺序表
void InitList(SqList& L) {
	L.length = 0;             //顺序表长度为0
}

int main()
{
	SqList L;      //声明一个顺序表
	InitList(L);   //初始化一个顺序表
	//将数据存入顺序表
	int list[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		L.data[i] = list[i];
		L.length++;
	}
	//打印整个数组
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	return 0;
}



