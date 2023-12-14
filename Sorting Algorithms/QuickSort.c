#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int i, j, pivot;
    pivot = arr[low];
    i = low+1;
    j = high;

    do
    {
      while(arr[i] < pivot)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }while(i < j);

    swap(&arr[j], &arr[low]);

    for(int i = 0; i < 9; i++ )
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return j; 
}


void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot + 1, high);
    }   
}

void printArr(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)    
    {
        scanf("%d",&arr[i]);
    }

    quickSort(arr, 0, n-1);
    printf("Sorted Array: ");
    printArr(arr, n);

    return 0;
}