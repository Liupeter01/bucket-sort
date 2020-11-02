#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int* arr, int n)
{
          for (int i = 0; i < n; ++i)
          {
                    printf("%-5d", arr[i]);
          }
          printf("\n");
}

void tsort(int *arr,int length)
{
          int temp[10][10] = { 0 };     
          int backup[10] = { 0 };  //备份二维数组
          int counter = 0;
          for (int i = 0; i < length; ++i)
          {
                    temp[(arr[i] / 10)][(arr[i] % 10)] = arr[i];
          }
          for (int i = 0; i < 10; ++i)
          {
                    for (int j = 0; j < 10; ++j)
                    {
                              if (temp[i][j] != 0 && counter!=10)
                              {
                                        backup[counter] = temp[i][j];
                                        ++counter;
                              }
                    }
          }
}

int main()
{
          time_t ts, te;
          time(&ts);
          srand((unsigned int)time(NULL));
          int* a = (int*)malloc(sizeof(int) * 100000);
          for (register int i = 0; i < 100000; ++i)
          {
                    a[i] = rand() % 100;
          }
          tsort(a, 100000);
          time(&te);
          display(a, 100000);
          printf("%f", difftime(te, ts));
          printf("\n");
          return 0;
}