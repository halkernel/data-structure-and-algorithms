#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
    int value; 

    /**
    * lower values indicate higher
    * priority in the queue
    */
    int priority;    
    struct node * next; 
}NODE; 

NODE * head = NULL;


NODE * create(int value, int priority){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).value = value;
  (*tmp).priority = priority;
  (*tmp).next = NULL;
  return tmp;
}

int p_head(){
  return (*head).value;
}

void enqueue(int value, int priority){    
    if(head == NULL){        
        head = create(value, priority);     
        return;       
    }

    if((*head).priority > priority){
      NODE * tmp = create(value, priority);
      (*tmp).next = head;
      head = tmp;
    }
    else{
      NODE * tmp = head;
      NODE * prev = tmp;
      while(tmp != NULL){        
        if((*tmp).priority > priority){
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

NODE * dequeue(NODE * head){
  NODE * tmp = head;
  head = (*head).next;
  (*tmp).next = NULL;
  return tmp;
}


void show_list(){
    NODE * tmp = head;
    while(tmp != NULL){        
        printf("%d -> ", (*tmp).value);
        tmp = (*tmp).next;
    }
    printf("\n");
}


int main(){

    enqueue(5, 4);
    enqueue(8, 3);
    enqueue(2, 2);
    enqueue(7, 1);
 
    show_list();

    dequeue(head);

    show_list();



    return 0; 
} 
