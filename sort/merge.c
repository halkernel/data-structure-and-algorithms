#include <stdio.h>


void merge(int * arr, int beg, int mid, int end){

    
}

void merge_sort(int * arr, int beg, int end){
	if(beg < end){
		int mid = (beg + end)/2;	
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid+1, end);	
		merge(arr, beg, end, mid);
	}
}

void print_arr(int * arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int size = 9;
	int arr[9] = {8,5,9,7,3,6,2,4,1};
	int beg = 0, end = size-1;	
	merge_sort(arr, beg, end);
	print_arr(arr, size);
	return 0;
}
 
