#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
    int value; 
    struct node * next; 
}NODE; 


NODE * create(int value){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).value = value;
  (*tmp).next = NULL;
  return tmp;
}


NODE * insert(NODE * node, int value){
    if(node == NULL){        
        return create(value);                
    }
    NODE * tmp = node;
    while((*tmp).next != NULL){        
        tmp = (*tmp).next;
    }
    (*tmp).next = create(value);
    return node;
}


void show_list(NODE * node){
    NODE * tmp = node;
    while(tmp != NULL){        
        printf("%d -> ", (*tmp).value);
        tmp = (*tmp).next;
    }
}


int main(){

    
    /* declaring two nodes without link them */  
    NODE * head;  

    /*               
    * head -> NULL            
    */ 

    head = create(1);
       
    /*          head
    *         +---+---+
    *         | 1 |   | -> NULL
    *         +---+---+
    */ 

   NODE * second = create(2);

    /*          head                second
    *         +---+---+           +---+---+
    *         | 1 |  -> NULL      | 2 |  -> NULL
    *         +---+---+           +---+---+
    */ 
   
    
    
    
    
    /* declaring two nodes linking them in a linked list */
    
    NODE * list = NULL;    
    
    /*              
    * 
    * list -> NULL                   
    * 
    */ 
    
    
    list = insert(list, 1);
    
    /*          list
    *         +---+---+
    *         | 1 |   | -> NULL
    *         +---+---+
    */ 

    list = insert(list, 2);
    
    /*          list                
    *         +---+---+  +---+---+
    *         | 1 |  --> | 2 |  --> NULL
    *         +---+---+  +---+---+
    */ 
    
    list = insert(list, 3);    
    
    /*          list                
    *         +---+---+  +---+---+  +---+---+
    *         | 1 |  --> | 2 |  --> | 3 |  --> NULL
    *         +---+---+  +---+---+  +---+---+
    */ 
    
    show_list(list);



    return 0; 
} 
