#pragma once
#include"LinkQueue.h"
#pragma comment(lib,"LinkQueue.lib")	//导入队列库

int DigitsCalculate(ElemType num);				  //计算位数
int GetMaxDigits(ElemType* arr, int size);		  //得到最大位数
int GetDetailedDigits(ElemType num, int digits); //根据指定的位数取出对应的数值

//传入数组的指针，队列数组的指针，和当前数据的位数信息
void Distribute(ElemType* arr, int arrsize, LinkQueue* queue, int digits);  //分发算法

//传入数组的指针以及数组的大小，队列数组的指针
void Collect(ElemType* arr, LinkQueue* queue);				//收集算法
void RadixSort(ElemType *arr,int size);	 //基数排序