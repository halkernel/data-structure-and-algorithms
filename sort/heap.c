#include <stdio.h>

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


void print_arr(int * arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void heapfy(int * arr, int beg, int end){
	int root = beg;
	int left = 2*beg+1;
	int right = 2*beg+2;
	if(left < end && arr[left] > arr[root]){
		root = left;			
	}
	if(right < end && arr[right] > arr[root]){
		root = right;
	}

	if(root != beg){
		swap(&arr[root], &arr[beg]);
		heapfy(arr, root, end);
	}

}



void heap_sort(int * arr, int size){	
	int i;
  for(i = size/2 - 1; i >= 0; i --){	
    heapfy(arr, i, size);
  }

	 for(i = size-1; i > 0; i--){
	 	swap(&arr[0], &arr[i]);
	 	heapfy(arr, 0, i);
	 }
}

int main(){
	int size = 9;
	int arr[9] = {28,55,99,47,3,36,22,45,19};
	int beg = 0, end = size;
	print_arr(arr, size);	
	heap_sort(arr, size);
	print_arr(arr, size);
	return 0;
}
 
