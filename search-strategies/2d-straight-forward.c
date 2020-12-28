#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <limits.h>

#define ln printf("\n");
#define n 10

/**
 * Problem description: Peak finder
 * - two dimensional version
 * - runs on an bidimensional array of numbers
 * consider [ ][c][ ][ ] a is considered a 2d peak
 *          [d][a][e][ ] or a hill iff a >= b,
 *          [ ][b][ ][ ] a >= d, a >=c, a >=e
 *          [ ][ ][ ][ ]
 *
 * https://stackoverflow.com/questions/65469831/find-all-peaks-in-a-matrix-nxn  
*/

static int arr[n][n];

int get(int i, int j){
    if (i < n && j < n) {
        return arr[i][j];
    }
    return INT_MIN;
}

  
void create_2darr(){
    int i,j; 
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            arr[i][j] = (10 + rand())%100; 
        }
    }      
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");    
    }        
    printf("\n");    
}

void find_hill(){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            //check corners
            int is_peak = arr[i][j] >= get(i + 1, j)
                    &&  arr[i][j] >= get(i, j + 1)
                    &&  arr[i][j] >= get(i - 1, j)
                    && arr[i][j] >= get(i, j - 1);
            
            printf(" -  "); 
            printf("%s", is_peak ? "/^\\ " : " -  ");                  
        }
        printf("\n");
    }     
}


int main(){ 

    srand ( time(NULL) ); 
    create_2darr();        
    find_hill();

    return 0; 
} 
