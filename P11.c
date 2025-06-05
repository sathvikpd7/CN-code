#include <stdio.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) 
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right)

{
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() 
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted:\n");
    for (int i = 0; i < n; i++)
         printf("%d ", arr[i]);
    printf("\nTime: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
