
#include <stdio.h>
#include <stdlib.h>

typedef struct h_node{
  char val;
  unsigned int frequency;
  struct h_node * left, * right;  
}H_NODE;

H_NODE * create(char data, unsigned long int frequency){
  H_NODE * tmp = malloc(sizeof(H_NODE));    
  (*tmp).val = data;
  (*tmp).frequency = frequency;
  (*tmp).left = NULL;
  (*tmp).right = NULL;  
  return tmp;
}


int main(){

  return 0;
}
