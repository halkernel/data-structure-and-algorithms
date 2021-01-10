#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
  
typedef struct node{
  int vertex;
  int weight;  
  struct node * next;  
}NODE;


typedef struct queue_node { 
    NODE * node; 
    int priority;
    struct queue_node * next; 
}PRIORITY_QUEUE_NODE; 



PRIORITY_QUEUE_NODE * queue = NULL;  
PRIORITY_QUEUE_NODE * rear = NULL;

int isEmpty(){
    if(queue == NULL){
        return 1;
    }    
    return 0;
}


PRIORITY_QUEUE_NODE * create(NODE * node, int priority){
  PRIORITY_QUEUE_NODE * tmp = (PRIORITY_QUEUE_NODE * ) malloc (sizeof ( PRIORITY_QUEUE_NODE ) );
  (*tmp).node = node;
  (*tmp).priority = priority;
  (*tmp).next = NULL;
  return tmp;
}

int firstEl(){
    printf("Top -> %d", (*(*rear).node).vertex);
    return (*(*rear).node).vertex;
}

void enqueue(NODE * node, int priority){    
    if(isEmpty()){
        queue = create(node, priority);
        rear = queue;
        return;
    }

    if((*rear).priority >= priority){
      PRIORITY_QUEUE_NODE * tmp = create(node, priority);
      (*rear).next = tmp;
      rear = tmp;
    }
    else{
      PRIORITY_QUEUE_NODE * tmp = queue;
      PRIORITY_QUEUE_NODE * prev = tmp;
      while(tmp != NULL){        
        if((*tmp).priority <= priority){
          PRIORITY_QUEUE_NODE * tmp2 = create(node, priority);
          (*prev).next = tmp2;
          (*tmp2).next = tmp;
          return;
        }        
        prev = tmp;
        tmp = (*tmp).next;        
      }
      (*tmp).next = create(node, priority);
    }
}


PRIORITY_QUEUE_NODE * dequeue(){
    if(isEmpty()){
        printf("The stack is Empty");
        return NULL;
    }
    
    PRIORITY_QUEUE_NODE * tmp = queue;
    
    if((*(*rear).node).vertex == (*(*queue).node).vertex){        
        queue = NULL;
        rear = NULL;
        return tmp;
    }
        
    PRIORITY_QUEUE_NODE * prev = tmp = queue;
    while((*(*tmp).node).vertex != (*(*rear).node).vertex){
        prev = tmp;
        tmp = (*tmp).next;
    }
    
    rear = prev;  
    (*prev).next = NULL;
    return tmp;
}


void show_queue(){
    
    PRIORITY_QUEUE_NODE * tmp = queue;
    printf("queue -> ");
    
    while(tmp != NULL){
        printf("[v:%d,p:%d] ", (*(*tmp).node).vertex, (*tmp).priority);        
        tmp = (*tmp).next;        
    }
    
    printf(" <- rear\n");
    
}
