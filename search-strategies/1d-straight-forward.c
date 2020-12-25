#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
#define n 10

/**
 * Problem description: Peak finder
 * - One dimensional version
 * - runs on an array of numbers
 * - position 2 is a peak if and only if:
 *   position 1 is le and position 3 is le
 * - the edges just look what is in its sides
*/


int * create_arr(){
    int i; 
    static int arr[10];  
    for(i = 0; i < n; i++)
        arr[i]=rand()%100;       
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return arr;
}

void find_peak(int arr[]){
    int i = 0;
    for(i = 0; i < n; i++){
        if(i == 0 && arr[i] >= arr[i+1]){
            printf("%d is a Peak\n",  arr[i]);
        }else if(i == n-1 && arr[i] >= arr[i-1]){
            printf("%d is a Peak\n",  arr[i]);
        }
        else if(arr[i] >= arr[i+1] && arr[i] >= arr[i-1]){        
            printf("%d is a Peak\n", arr[i]);
        }        
    }
}
  

int main(){                     
    int * arr = create_arr();
    find_peak(arr);
    return 0; 
} 
