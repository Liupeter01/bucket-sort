#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

#define ElemType int
#define ERRORCODE 0x7ffffff

typedef struct LinkNode       //链表
{
          ElemType data;      //数据域
          struct LinkNode* next;  //指针域
}LinkNode;

typedef struct LinkQueue      //链式队列
{
          LinkNode* front;    //头指针
          LinkNode* rear;     //尾指针
}LinkQueue;

LinkNode* CreateNode(ElemType data);				  //创建结点
BOOL IsQueueEmpty(LinkQueue Q);              //链式队列的判空

/*链式队列的初始化摧毁与清除功能*/
void InitLinkQueue(LinkQueue* Q);           //链式队列的初始化
void ClearLinkQueue(LinkQueue* Q);           //链式队列的清除
void DestroyLinkQueue(LinkQueue* Q);           //链式队列的摧毁

/*链式队列的显示输出*/
void DisplayLinkQueue(LinkQueue Q);           //链式队列的输出

/*入队以及出队操作*/
void EnQueue(LinkQueue* Q, ElemType x);          //链式队列的入队操作
BOOL DeQueue(LinkQueue* Q, ElemType* e);             //链式队列的出队操作

/*其他功能*/
ElemType GetTop(LinkQueue Q);              //链式队列获取队头的值
int length(LinkQueue Q);                 //链式队列长度