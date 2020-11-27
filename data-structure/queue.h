#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
  
typedef struct queue_node { 
    int value; 
    struct queue_node * next; 
}QUEUE_NODE; 

QUEUE_NODE * queue = NULL;  
QUEUE_NODE * rear = NULL;

QUEUE_NODE * create(int value){
  QUEUE_NODE * tmp = (QUEUE_NODE * ) malloc (sizeof ( QUEUE_NODE ) );
  (*tmp).value = value;
  (*tmp).next = NULL;
  return tmp;
}

int isEmpty(){
    if(queue == NULL){
        return 1;
    }    
    return 0;
}

QUEUE_NODE * dequeue(){
    if(isEmpty()){
        printf("The stack is Empty");
        return NULL;
    }
    
    QUEUE_NODE * tmp = queue;
    
    if((*rear).value == (*queue).value){        
        queue = NULL;
        rear = NULL;
        return tmp;
    }
        
    QUEUE_NODE * prev = tmp = queue;
    while((*tmp).value != (*rear).value){
        prev = tmp;
        tmp = (*tmp).next;
    }
    
    rear = prev;  
    (*prev).next = NULL;
    return tmp;
}


int firstEl(){
    printf("Top -> %d", (*rear).value);
    return (*rear).value;
}

void enqueue(int value){
    if(isEmpty()){
        queue = create(value);
        rear = queue;
        return;
    }
    QUEUE_NODE * tmp = create(value);    
    (*tmp).next = queue;
    queue = tmp;
}

void show_queue(){
    
    QUEUE_NODE * tmp = queue;
    printf("queue -> ");
    
    while(tmp != NULL){
        printf("%d ", (*tmp).value);        
        tmp = (*tmp).next;        
    }
    
    printf(" <- rear");
    
}

void clear(){
    queue = NULL;
}
