#include <stdio.h>





void print_arr(int * arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
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
 
