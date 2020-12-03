#include"RadixSorting.h"

int DigitsCalculate(ElemType num)		  //����λ��
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

int GetMaxDigits(ElemType* arr, int size)		  //�õ����λ��
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

int GetDetailedDigits(ElemType num, int digits)  //����ָ����λ��ȡ����Ӧ����ֵ
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

//���������ָ���Լ�����Ĵ�С�����������ָ���Լ����еĴ�С���͵�ǰ���ݵ�λ����Ϣ
void Distribute(ElemType* arr, int arrsize, LinkQueue* queue, int digits) //�ַ��㷨
{
		  for (int i = 0; i < arrsize; ++i)
		  {
					EnQueue(&queue[GetDetailedDigits(arr[i], digits)], arr[i]);			  //��þ���λ����ֵ�����뵽����
		  }
}

//���������ָ���Լ�����Ĵ�С�����������ָ���Լ����еĴ�С
void Collect(ElemType* arr, LinkQueue* queue)			//�ռ��㷨
{
		  int start = 0;
		  for (int i = 0; i < 10; ++i)			  //�ռ�����
		  {
					while (!IsQueueEmpty(queue[i]))
					{
							  DeQueue(&queue[i], &arr[start++]);
					}
		  }
}

void RadixSort(ElemType* arr, int size)	 //��������
{
		  int DistributeCollectTime = GetMaxDigits(arr,size);			//�������ռ��Ĵ�������ֵ�����ݵ����λ������
		  LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue) * 10);		//������10�Ļ���
		  for (int i = 0; i < 10; ++i)			  //��ʼ������
		  {
					InitLinkQueue(&queue[i]);
		  }

		  for (int i = 0; i < DistributeCollectTime; ++i)
		  {
					Distribute(arr, size, queue, i);						//�ַ��㷨
					Collect(arr, queue);
		  }

		  for (int i = 0; i < 10; ++i)			  //�ݻٶ���
		  {
					DestroyLinkQueue(&queue[i]);
		  }
		  return;
}