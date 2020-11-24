#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
  
typedef struct node { 
    int value; 
    struct node * next; 
}NODE; 

NODE * stack = NULL;  

NODE * create(int value){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).value = value;
  (*tmp).next = NULL;
  return tmp;
}

int isEmpty(){
    if(stack == NULL){
        return 1;
    }    
    return 0;
}

NODE * pop(){
    
    if(isEmpty()){
        printf("The stack is Empty");
        return NULL;
    }
    NODE * tmp = stack;    
    stack = (*stack).next;
    return tmp;
    
}


int topEl(){
    printf("Top -> %d", (*stack).value);
    return (*stack).value;
}

void push(int value){
    if(isEmpty()){
        stack = create(value);
    }
    NODE * tmp = create(value);
    (*tmp).next = stack;
    stack = tmp;
}

void show_stack(){
    if(!isEmpty()){
        NODE * tmp = stack;
        while((*tmp).next != NULL){
            printf("[%d]\n", (*tmp).value);
            tmp = (*tmp).next;
        }
    }    
    else{
        printf("The stack is Empty");
    }
}

void clear(){
    stack = NULL;
}


int main(){
              
    push(10);
    push(5);
    push(12);
    
    topEl();
    ln
    
    show_stack();    
    pop();    
    ln    
    
    show_stack();
    pop();    
    ln    
    
    show_stack();
    pop();    
    ln 
    
    show_stack();
        
    clear();
    
    show_stack();


    return 0; 
} 
