#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#define MaxSize 10   //������󳤶�

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];   //�þ�̬����������Ԫ��
	int length;               //˳���ĵ�ǰ����
}SqList;                      //˳�������Ͷ���

//��ʼ��һ��˳���
void InitList(SqList& L) {
	L.length = 0;             //˳�����Ϊ0
}

int main()
{
	SqList L;      //����һ��˳���
	InitList(L);   //��ʼ��һ��˳���
	//�����ݴ���˳���
	int list[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		L.data[i] = list[i];
		L.length++;
	}
	//��ӡ��������
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	return 0;
}



