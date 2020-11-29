#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");


typedef struct node{
    int value;
	struct node* left;
	struct node* right;
}NODE;


typedef struct queue_node { 
    NODE * node; 
    struct queue_node * next; 
}QUEUE_NODE; 

QUEUE_NODE * queue = NULL;
QUEUE_NODE * rear = NULL;
  

QUEUE_NODE * create(NODE * value){
  QUEUE_NODE * tmp = (QUEUE_NODE * ) malloc (sizeof ( QUEUE_NODE ) );
  (*tmp).node = value;
  (*tmp).next = NULL;
  return tmp;
}

int isQueueEmpty(){    
    if(queue == NULL){        
        return 1;
    }            
    return 0;
}

QUEUE_NODE * dequeue(){
    if(isQueueEmpty()){
        printf("The stack is Empty");
        return NULL;
    }
    
    QUEUE_NODE * tmp = queue;
    
    if((*(*rear).node).value == (*(*queue).node).value){        
        queue = NULL;
        rear = NULL;
        return tmp;
    }
        
    QUEUE_NODE * prev = tmp = queue;
    while((*(*tmp).node).value != (*(*rear).node).value){
        prev = tmp;
        tmp = (*tmp).next;
    }
    
    rear = prev;  
    (*prev).next = NULL;
    return tmp;
}


int firstEl(){
    printf("Top -> %d", (*(*rear).node).value);
    return (*(*rear).node).value;
}

void enqueue(NODE * node){
    if(isQueueEmpty()){
        queue = create(node);
        rear = queue;
        return;
    }
    QUEUE_NODE * tmp = create(node);    
    (*tmp).next = queue;
    queue = tmp;
}

void show_queue(){
    
    QUEUE_NODE * tmp = queue;
    printf("queue -> ");
    
    while(tmp != NULL){
        printf("%d ", (*(*tmp).node).value);        
        tmp = (*tmp).next;        
    }
    
    printf(" <- rear");
    
}

void clear(){
    queue = NULL;
}
