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


int partition(int * arr, int beg, int end){
    int pivot = arr[end];
    int j, i = beg - 1;    


    for(j = beg; j < end; j++){
      if(arr[j] <= pivot){
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i+1], &arr[end]);
    return i + 1;    
		
}

void shell_sort(int * arr, int beg, int end){	
	int i, j, k;
  for(i = end/2; i > 0; i /=2 ){
    for(j = i; j < end; j++){
      int tmp = arr[j];
      for(k = j; k >= i && arr[j-i] > tmp; j-=i){
        arr[k] = arr[k-i];
      }
      arr[j] = tmp;
    }
  }
}

int main(){
	int size = 9;
	int arr[9] = {28,55,99,47,3,36,22,45,19};
	int beg = 0, end = size;
	print_arr(arr, size);	
	shell_sort(arr, beg, end);
	print_arr(arr, size);
	return 0;
}
 
