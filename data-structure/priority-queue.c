#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
  
typedef struct node { 
    int value; 

    /**
    * lower values indicate higher
    * priority in the queue
    */
    int priority;    
    struct node * next; 
}NODE; 

NODE * queue = NULL;  
NODE * rear = NULL;

int isEmpty(){
    if(queue == NULL){
        return 1;
    }    
    return 0;
}


NODE * create(int value, int priority){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).value = value;
  (*tmp).priority = priority;
  (*tmp).next = NULL;
  return tmp;
}

int firstEl(){
    printf("Top -> %d", (*rear).value);
    return (*rear).value;
}

void enqueue(int value, int priority){    
    if(isEmpty()){
        queue = create(value, priority);
        rear = queue;
        return;
    }

    if((*rear).priority > priority){
      NODE * tmp = create(value, priority);
      (*rear).next = tmp;
      rear = tmp;
    }
    else{
      NODE * tmp = queue;
      NODE * prev = tmp;
      while(tmp != NULL){        
        if((*tmp).priority < priority){
          NODE * tmp2 = create(value, priority);
          (*prev).next = tmp2;
          (*tmp2).next = tmp;
          return;
        }        
        prev = tmp;
        tmp = (*tmp).next;        
      }
      (*tmp).next = create(value, priority);
    }
}


NODE * dequeue(){
    if(isEmpty()){
        printf("The stack is Empty");
        return NULL;
    }
    
    NODE * tmp = queue;
    
    if((*rear).value == (*queue).value){        
        queue = NULL;
        rear = NULL;
        return tmp;
    }
        
    NODE * prev = tmp = queue;
    while((*tmp).value != (*rear).value){
        prev = tmp;
        tmp = (*tmp).next;
    }
    
    rear = prev;  
    (*prev).next = NULL;
    return tmp;
}


void show_queue(){
    
    NODE * tmp = queue;
    printf("queue -> ");
    
    while(tmp != NULL){
        printf("[v:%d,p:%d] ", (*tmp).value, (*tmp).priority);        
        tmp = (*tmp).next;        
    }
    
    printf(" <- rear\n");
    
}

int main(){

    enqueue(5, 9);
    show_queue();
    enqueue(8, 6);    
    show_queue();
    enqueue(12, 8);
    show_queue();
    dequeue();
    show_queue();
    dequeue();
    show_queue();
    enqueue(2, 2);
    enqueue(7, 1);
    show_queue();
   

    return 0; 
} 
