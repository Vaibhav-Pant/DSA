#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int n, int arr[])
{
    for( int i = 0; i < n-1; i++ )
    {
        int swapped = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
        {
            break;
        }
    }
}

void printArr(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(n, arr);
    printf("Sorted Array: ");
    printArr(arr,n);

    return 0;
}