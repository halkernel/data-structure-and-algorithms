#include <stdio.h>


void insertion_sort(int * arr, int size){
	int i, j, val;
	for(i = 1; i < size; i++){
		val = arr[i];
		j = i - 1; //prev
		while(j >=0 && arr[j] > val){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = val; 
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
	insertion_sort(arr, size);
	print_arr(arr, size);
	return 0;
}
