#include"RadixSorting.h"

int main()
{
          ElemType arr[] = { 278,109,63,930,589,184,505,269,8,83};
          RadixSort(arr, sizeof(arr) / sizeof(ElemType));
          for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
          {
                    printf("%d ", arr[i]);
          }
          printf("\n");
          return 0;
}