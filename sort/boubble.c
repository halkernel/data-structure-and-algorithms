 #include <stdio.h>

void bubble_sort(int * arr, int size){
	int i, j, n;
	for(i =0; i < size; i++){		
		for(j=0; j < size; j++){
			if(arr[j] > arr[j+1]){
				int n = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = n;
			}
		}
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
	bubble_sort(arr, size);
	print_arr(arr, size);
	return 0;
}

