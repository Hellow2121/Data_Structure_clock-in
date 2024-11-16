#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10   //默认最大长度
typedef int ElemType;
typedef struct SeqList {
	ElemType* data;   //指向动态分配数组的指针
	int MaxSize;      //顺序表的最大容量
	int length;       //顺序表的当前长度
}SeqList;

//初始化一个顺序表
void InitList(SeqList& L) {
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));   //用malloc函数申请一片连续的存储空间
	L.MaxSize = InitSize;   //将顺序表的最大容量设置为默认最大长度
	L.length = 0;           //初始化当前表长为0
}

//增加动态数组的长度
void IncreaseSize(SeqList& L, int len) {
	ElemType* p = L.data;   //暂存改前数组首地址
	L.data = (ElemType*)malloc((L.MaxSize + len) * sizeof(ElemType));   //为数组重新申请一片原基础上加长新的空间
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];   //将改前数组数据拷贝的新数组里
	}
	L.MaxSize += len;   //增加数组的最大容量
	free(p);   //释放改前数组存储空间
}

//顺序表中按位序插入元素
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) return false;   //插入位序超出范围
	if (L.length >= L.MaxSize) return false;   //顺序表已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.data[j + 1] = L.data[j];    //将位序i及其后面的元素都后移一位
	L.data[i - 1] = e;   //将e插入位序i处
	L.length++;   //顺序表长度加1
	return true;   //返回插入成功
}

//顺序表中按位序删除元素
bool ListDelete(SeqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length) return false;   //删除位序超出范围
	e = L.data[i - 1];   //返回位序i的元素
	for (int j = i; j <= L.length - 1; j++)
		L.data[j - 1] = L.data[j];   //将位序i及其后面的元素都前移一位
	L.length--;   //顺序表长度减1
	return true;   //返回删除成功
}

//按值查找元素
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e) return i + 1;   //遍历整个数组，查找成功返回位序
	return 0;   //退出循环查找失败
}

int main()
{
	SeqList L;          //声明一个顺序表
	InitList(L);        //初始化顺序表
	IncreaseSize(L, 5);
	//往顺序表中插入若干元素
	ElemType list[11] = { 1,12,13,14,15,16,17,18,19,110,111 };
	for (int i = 0; i < 11; i++) {
		L.data[i] = list[i];
		L.length++;
	}
	//删除位序11处的元素
	ElemType e;
	if(ListDelete(L, 11, e))
		printf("%d\n", e);
	//在位序3处插入元素3
	if(ListInsert(L, 3, 3))
		for (int i = 0; i < L.length; i++) 
			printf("%d ", L.data[i]);
	if (e = LocateElem(L, 3)) 
		printf("\n查找成功,位序为%d。", e);
	else printf("\n查找失败，哭。");
	return 0;
}


