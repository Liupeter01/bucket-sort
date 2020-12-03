#include"RadixSorting.h"

int DigitsCalculate(ElemType num)		  //计算位数
{
		  static int count = 0;
		  if (num == 0)
		  {
					int  p = count;
					count = 0;
					return p;
		  }
		  else
		  {
					count++;
					return DigitsCalculate(num / 10);
		  }
}

int GetMaxDigits(ElemType* arr, int size)		  //得到最大位数
{
		  ElemType maxnum = 0;
		  for (int i = 0; i < size; ++i)
		  {
					if (maxnum < arr[i])
					{
							  maxnum = arr[i];
					}
		  }
		  return DigitsCalculate(maxnum);
}

int GetDetailedDigits(ElemType num, int digits)  //根据指定的位数取出对应的数值
{
		  ElemType key = num;
		  while (digits >= 0)
		  {
					key = num % 10;
					num /= 10;
					digits--;
		  }
		  return key;
}

//传入数组的指针以及数组的大小，队列数组的指针以及队列的大小，和当前数据的位数信息
void Distribute(ElemType* arr, int arrsize, LinkQueue* queue, int digits) //分发算法
{
		  for (int i = 0; i < arrsize; ++i)
		  {
					EnQueue(&queue[GetDetailedDigits(arr[i], digits)], arr[i]);			  //获得具体位的数值并加入到队列
		  }
}

//传入数组的指针以及数组的大小，队列数组的指针以及队列的大小
void Collect(ElemType* arr, LinkQueue* queue)			//收集算法
{
		  int start = 0;
		  for (int i = 0; i < 10; ++i)			  //收集数据
		  {
					while (!IsQueueEmpty(queue[i]))
					{
							  DeQueue(&queue[i], &arr[start++]);
					}
		  }
}

void RadixSort(ElemType* arr, int size)	 //基数排序
{
		  int DistributeCollectTime = GetMaxDigits(arr,size);			//分配与收集的次数，该值由数据的最大位数决定
		  LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue) * 10);		//适用于10的基数
		  for (int i = 0; i < 10; ++i)			  //初始化队列
		  {
					InitLinkQueue(&queue[i]);
		  }

		  for (int i = 0; i < DistributeCollectTime; ++i)
		  {
					Distribute(arr, size, queue, i);						//分发算法
					Collect(arr, queue);
		  }

		  for (int i = 0; i < 10; ++i)			  //摧毁队列
		  {
					DestroyLinkQueue(&queue[i]);
		  }
		  return;
}