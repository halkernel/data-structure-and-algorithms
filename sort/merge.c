#include <stdio.h>




void merge(int * arr, int beg, int mid, int end){
		int i, j, k;
		int s1 = mid - beg + 1;
		int s2 = end - mid;

		int tmp_left[s1], tmp_right[s2];

		for(i = 0; i < s1; i++){
			tmp_left[i] = arr[beg + i];
		}
		for(j = 0; j < s2; j++){
			tmp_right[j] = arr[mid + 1 + j];
		}

		i = 0, j = 0, k = beg;

		while(i < s1 && j < s2){
			if(tmp_left[i] <= tmp_right[j]){
				arr[k] = tmp_left[i];
				i++;
			}else{
				arr[k] = tmp_right[j];
				j++;
			}
			k++;			
		}
		
		while (i < s1){
			arr[k] = tmp_left[i];
			i++;
			k++;
		}		

		while (j < s2){
			arr[k] = tmp_right[j];
			j++;
			k++;
		}
		
}

void merge_sort(int * arr, int beg, int end){	
	if(beg < end){
		int mid = (beg + end)/2;	
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid+1, end);	
		merge(arr, beg, mid, end);
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
	int arr[9] = {28,55,99,47,3,36,22,45,19};
	int beg = 0, end = size-1;
	print_arr(arr, size);	
	merge_sort(arr, beg, end);
	print_arr(arr, size);
	return 0;
}
 
