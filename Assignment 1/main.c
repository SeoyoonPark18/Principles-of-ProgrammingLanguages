#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Swap function to swap two integers at their addresses*/
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*Helper function for quick_sort*/
int Partition(int A[], int start, int end)
{
    int pivot = A[start];
    int x = start + 1; 
    bool crossed = false;
    while(!crossed)
    {
        while(x <= end && A[x] <= pivot) 
        {
            x++;
        }
        while(end >= x && A[end] >= pivot) 
        {
            end--; 
        }
        if(end < x) 
        {
            crossed = true;
        }
        else
        {
            swap(&A[x], &A[end]);
        }
    }
    swap(&A[start], &A[end]); 
    return end;
}

/*quicksort*/
void quickSort(int A[], int start, int end)
{
    if(start < end)
    {
        int q = Partition(A, start, end);
        quickSort(A, start, q - 1);
        quickSort(A, q + 1, end);
    }
}

void qs(int *a, int n)
{
  quickSort(a, 0, n);
}

void merge(int *a, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
  
    for (i = 0; i < n1; i++) {
        L[i] = a[l + i]; 
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j]; 
    }
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            a[k] = L[i]; 
            i++; 
        } 
        else { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        a[k] = R[j]; 
        j++; 
        k++; 
    }
  
    free(L);
    free(R);
}

void merge_sort(int *a, int l, int r) // merge sort an array a with n elements in C
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        merge_sort(a, l, m); 
        merge_sort(a, m + 1, r); 
  
        merge(a, l, m, r); 
    } 
} 

void ms(int *a, int n)
{
  merge_sort(a, 0, n);
}

int main(void) 
{
  // test case 1 with normal array
  int A[] = {30, 21, 52, 43, 14, 35, 26, 57, 48, 19, 31, 22, 53, 44, 15, 36, 27, 58, 49, 10};
  size_t size = sizeof(A) / sizeof(A[0]);
  //Allocate memory for array
  int* B = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i) 
  {
    B[i] = A[i];
  }
  printf("Test Case 1: normal elements \n");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", A[i]);
  }
  qs(A, size - 1);
  printf("\nSorted Array using quicksort: \n");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", A[i]);
  }
  ms(B, size - 1);
  printf("\nSorted Array using mergesort: \n");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", B[i]);
  }
  printf("\n");
  //Free array
  free(B);
  // test case 2 with empty array
  int A2[] = {};
  size_t size2 = sizeof(A2) / sizeof(A2[0]);
  printf("\nTest Case 2: empty array \n");
  for(int i = 0; i < size2; i++)
  {
    printf("%d ", A2[i]);
  }
  qs(A2, size2 - 1);
  printf("\nSorted Array using quicksort: \n");
  for(int i = 0; i < size2; i++)
  {
    printf("%d ", A2[i]);
  }
  ms(A2, size2 - 1);
  printf("\nSorted Array using mergesort: \n");
  for(int i = 0; i < size2; i++)
  {
    printf("%d ", A2[i]);
  }
  // test case 3 with randomized and negative inputs
  //
    srand(time(NULL)); // seed the random number generator

    int A3[20];
    size_t size3 = sizeof(A) / sizeof(A[0]);
    //Allocate memory for array
    int* B3 = (int*)malloc(size3 * sizeof(int));

    printf("\nTest Case 3: randomized and negative numbers\n");

    for(int i = 0; i < 20; i++) {
        A3[i] = rand() % 201 - 100; // generate random numbers between -100 and 100
        B3[i] = A3[i];
        printf("%d ", A3[i]);
    }

    qs(A3, 19);
    printf("\nSorted array using quicksort:\n");
    for(int i = 0; i < 20; i++) {
        printf("%d ", A3[i]);
    }

    ms(B3, 19);
    printf("\nSorted array using mergesort:\n");
    for(int i = 0; i < 20; i++) {
        printf("%d ", B3[i]);
    }

    free(B3);
    printf("\n");
  
  return 0;
}