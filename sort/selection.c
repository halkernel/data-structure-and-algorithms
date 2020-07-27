#include <stdio.h>


void selection_sort(int * arr, int size){
	int i, j, min, index, swap;
	for(i =0; i < size; i++){
		min = arr[i];
		for(j=i; j < size; j++){
			if(min > arr[j]){
				min = arr[j];
				index = j;
			}
		}
		swap = arr[index];
		arr[index] = arr[i];
		arr[i] = min;
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
	selection_sort(arr, size);
	print_arr(arr, size);
	return 0;
}
 
