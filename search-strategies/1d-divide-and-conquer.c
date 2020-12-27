#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

#define ln printf("\n");
#define n 10

/**
 * Problem description: Peak finder
 * - One dimensional version
 * - runs on an array of numbers
 * - a peak or more must exist in A[low...mid-1] iff a[mid] < a[mid-1]
 * - symmetrically for A[mid+1 ... high] iff a[mid] < a[mid+1]
 * 
 * - if i[mid] < i[mid-1] then look only at
 *      left half 1 ... mid-1 for a peak. 
 *   else if i[mid] < i[mid+1] then look only at
 *      right half mid+1 ... n for a peak
 *   else mid is a peak
*/


void find_peak_dc(int arr[], int beg, int end){
    int mid = (beg + end)/2;    
    if(arr[mid] >= arr[mid+1] && arr[mid] >= arr[mid-1]){
        printf("%d is a Peak\n",  arr[mid]);
    }
    if(arr[mid] < arr[mid-1]){
        find_peak_dc(arr, beg, mid-1);
    }
    if(arr[mid] < arr[mid+1]){
        find_peak_dc(arr, mid+1, end);
    }
}

int * create_arr(){
    int i; 
    static int arr[n];  
    for(i = 0; i < n; i++)
        arr[i]=rand()%100;       
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return arr;
}
 
int main(){
    srand ( time(NULL) );
    int * arr = create_arr();
    find_peak_dc(arr, 0, n);                 

    return 0; 
} 
