#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

#define ElemType int
#define ERRORCODE 0x7ffffff

typedef struct LinkNode       //����
{
          ElemType data;      //������
          struct LinkNode* next;  //ָ����
}LinkNode;

typedef struct LinkQueue      //��ʽ����
{
          LinkNode* front;    //ͷָ��
          LinkNode* rear;     //βָ��
}LinkQueue;

LinkNode* CreateNode(ElemType data);				  //�������
BOOL IsQueueEmpty(LinkQueue Q);              //��ʽ���е��п�

/*��ʽ���еĳ�ʼ���ݻ����������*/
void InitLinkQueue(LinkQueue* Q);           //��ʽ���еĳ�ʼ��
void ClearLinkQueue(LinkQueue* Q);           //��ʽ���е����
void DestroyLinkQueue(LinkQueue* Q);           //��ʽ���еĴݻ�

/*��ʽ���е���ʾ���*/
void DisplayLinkQueue(LinkQueue Q);           //��ʽ���е����

/*����Լ����Ӳ���*/
void EnQueue(LinkQueue* Q, ElemType x);          //��ʽ���е���Ӳ���
BOOL DeQueue(LinkQueue* Q, ElemType* e);             //��ʽ���еĳ��Ӳ���

/*��������*/
ElemType GetTop(LinkQueue Q);              //��ʽ���л�ȡ��ͷ��ֵ
int length(LinkQueue Q);                 //��ʽ���г���