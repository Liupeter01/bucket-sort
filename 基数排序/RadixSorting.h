#pragma once
#include"LinkQueue.h"
#pragma comment(lib,"LinkQueue.lib")	//������п�

int DigitsCalculate(ElemType num);				  //����λ��
int GetMaxDigits(ElemType* arr, int size);		  //�õ����λ��
int GetDetailedDigits(ElemType num, int digits); //����ָ����λ��ȡ����Ӧ����ֵ

//���������ָ�룬���������ָ�룬�͵�ǰ���ݵ�λ����Ϣ
void Distribute(ElemType* arr, int arrsize, LinkQueue* queue, int digits);  //�ַ��㷨

//���������ָ���Լ�����Ĵ�С�����������ָ��
void Collect(ElemType* arr, LinkQueue* queue);				//�ռ��㷨
void RadixSort(ElemType *arr,int size);	 //��������