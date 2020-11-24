#include <stdio.h> 
#include <stdlib.h> 

#define ln printf("\n");
  
typedef struct node { 
    int value; 
    struct node * next; 
}NODE; 

NODE * queue = NULL;  
NODE * rear = NULL;

NODE * create(int value){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
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
    NODE * tmp = create(value);    
    (*tmp).next = queue;
    queue = tmp;
}

void show_queue(){
    
    NODE * tmp = queue;
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


int main(){
              
    enqueue(10);
    show_queue();  
    ln
    
    enqueue(5);    
    show_queue();  
    ln
    
    enqueue(12);
    show_queue();  
    ln
    
    firstEl();
    ln
    
    show_queue();    
    dequeue();    
    ln    
    
    show_queue();
    dequeue();    
    ln    
    
    show_queue();
    dequeue();    
    ln 
    
    enqueue(8);
    enqueue(22);
    show_queue();
    ln    
            
    clear();
    
    
    show_queue();


    return 0; 
} 
