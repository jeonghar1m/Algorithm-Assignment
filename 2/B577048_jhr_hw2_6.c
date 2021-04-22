//Reference: https://ehpub.co.kr/tag/clocks_per_sec/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int sorted[MAX_SIZE];   // Additional memoryh for merge sort

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  			// 왼쪽 배열의 시작 인덱스
	j = mid + 1;  		// 오른쪽 배열의 시작 인덱스
	k = left;			// sorted array의 시작 인덱스

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i>mid)	// 오른쪽 배열에 아직 남아 있는 원소가 있는 경우
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];

	else if (j>right)  // 왼쪽 배열에 아직 원소가 남아 있는 경우
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
			
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	return;
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;     
		merge_sort(list, left, mid);   
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right);    
	}
}


int partition(int arr[], int low, int high){
    int i, pivot, pIndex, temp;

    pivot = arr[high];       // pivot 값을 배열 마지막 값으로 할당
    pIndex = low;           

    for (i=low; i<high; i++){    // pivot 보다 작은 값들을 scan
        if (arr[i] < pivot){
            SWAP(arr[i], arr[pIndex], temp);
            pIndex++;
        }
    }
    SWAP(arr[pIndex], arr[high], temp);   // pivot 값을 pIndex 위치로 이동

    return pIndex;    
}

void quicksort(int arr[], int low, int high){
    int pIndex;

    if (low < high){
        pIndex = partition(arr, low, high);
        quicksort(arr, low, pIndex-1);
        quicksort(arr, pIndex+1, high);
    }
    return;
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = 0; i<n-1; i++) {
		for (j = 0; j<n-1-i; j++)
			if (list[j]>list[j+1])
				SWAP(list[j], list[j+1], temp);
	}

    return;
}

void selection_sort(int list[], int n)
{
	int i, j, minIndex, temp;
	for (i = 0; i < n-1; i++) {
		minIndex = i;
		for (j = i+1; j<n; j++) 	
			if (list[j] < list[minIndex]) 
				minIndex = j;
		SWAP(list[i], list[minIndex], temp);
	}
	return;
}

void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (i = 1; i<n; i++) {
		key = list[i];
		j = i-1;
		while (j >= 0 && list[j]>key){
			list[j + 1] = list[j];   //move the key value into right position
			j = j-1;
		}
		list[j + 1] = key;
	}

	return;
}

// Shellsort 
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}

    return;
}

void shell_sort(int list[], int n)   // n: size
{
	int i, gap;

	for (gap = n/2; gap>0; gap = gap/2) {
		if ((gap % 2) == 0) 
            gap++;
		for (i = 0; i<gap; i++)		
			inc_insertion_sort(list, i, n - 1, gap);
	}
    return;
}

int main(void)
{
	int i;
	srand(time(NULL));

    clock_t st, et;

    // Bubble sort
    st = clock();
	bubble_sort(list, MAX_SIZE); 
    et = clock();
    printf("Bubble sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

	for (i = 0; i<MAX_SIZE; i++)      
		list[i] = rand() % 100000;     

    // Selection sort
    st = clock();
    selection_sort(list, MAX_SIZE);
    et = clock();
    printf("Selection sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

    // Insertion sort
    st = clock();
	insertion_sort(list, MAX_SIZE); 
    et = clock();
    printf("Insertion sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

    // Shell sort
    st = clock();         
	shell_sort(list, MAX_SIZE); 
	et = clock();
    printf("Shell sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

    // Merge sort
    st = clock();       
	merge_sort(list, 0, MAX_SIZE-1); 
    et = clock();
	printf("Merge sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

    // Quicksort
    st = clock();       
	quicksort(list, 0, MAX_SIZE-1); 
    et = clock();
	printf("Quick sort 수행시간: %d clocks (1sec = %d clocks)\n", et - st, CLOCKS_PER_SEC);

	return 0;
}