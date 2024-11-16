#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10   //Ĭ����󳤶�
typedef int ElemType;
typedef struct SeqList {
	ElemType* data;   //ָ��̬���������ָ��
	int MaxSize;      //˳�����������
	int length;       //˳���ĵ�ǰ����
}SeqList;

//��ʼ��һ��˳���
void InitList(SeqList& L) {
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));   //��malloc��������һƬ�����Ĵ洢�ռ�
	L.MaxSize = InitSize;   //��˳���������������ΪĬ����󳤶�
	L.length = 0;           //��ʼ����ǰ��Ϊ0
}

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList& L, int len) {
	ElemType* p = L.data;   //�ݴ��ǰ�����׵�ַ
	L.data = (ElemType*)malloc((L.MaxSize + len) * sizeof(ElemType));   //Ϊ������������һƬԭ�����ϼӳ��µĿռ�
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];   //����ǰ�������ݿ�������������
	}
	L.MaxSize += len;   //����������������
	free(p);   //�ͷŸ�ǰ����洢�ռ�
}

//˳����а�λ�����Ԫ��
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) return false;   //����λ�򳬳���Χ
	if (L.length >= L.MaxSize) return false;   //˳�������
	for (int j = L.length - 1; j >= i - 1; j--)
		L.data[j + 1] = L.data[j];    //��λ��i��������Ԫ�ض�����һλ
	L.data[i - 1] = e;   //��e����λ��i��
	L.length++;   //˳����ȼ�1
	return true;   //���ز���ɹ�
}

//˳����а�λ��ɾ��Ԫ��
bool ListDelete(SeqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length) return false;   //ɾ��λ�򳬳���Χ
	e = L.data[i - 1];   //����λ��i��Ԫ��
	for (int j = i; j <= L.length - 1; j++)
		L.data[j - 1] = L.data[j];   //��λ��i��������Ԫ�ض�ǰ��һλ
	L.length--;   //˳����ȼ�1
	return true;   //����ɾ���ɹ�
}

//��ֵ����Ԫ��
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e) return i + 1;   //�����������飬���ҳɹ�����λ��
	return 0;   //�˳�ѭ������ʧ��
}

int main()
{
	SeqList L;          //����һ��˳���
	InitList(L);        //��ʼ��˳���
	IncreaseSize(L, 5);
	//��˳����в�������Ԫ��
	ElemType list[11] = { 1,12,13,14,15,16,17,18,19,110,111 };
	for (int i = 0; i < 11; i++) {
		L.data[i] = list[i];
		L.length++;
	}
	//ɾ��λ��11����Ԫ��
	ElemType e;
	if(ListDelete(L, 11, e))
		printf("%d\n", e);
	//��λ��3������Ԫ��3
	if(ListInsert(L, 3, 3))
		for (int i = 0; i < L.length; i++) 
			printf("%d ", L.data[i]);
	if (e = LocateElem(L, 3)) 
		printf("\n���ҳɹ�,λ��Ϊ%d��", e);
	else printf("\n����ʧ�ܣ��ޡ�");
	return 0;
}


