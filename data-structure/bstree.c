#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define ln printf("\n");
#define psize 15



NODE * head = NULL;

typedef enum {false, true} bool;

void find_and_delete_by_merge(NODE * current, NODE * previous, int value);
NODE * delete_previous(NODE * current, NODE * previous, int value);
void remove_node_with_one_orphan(NODE * current, NODE * children, NODE * previous);

void pre_print(NODE * current);
void in_print(NODE * current);
void post_print(NODE * current);

NODE * create_node(char value);
void add_node(char value, NODE * current);

bool are_children_null(NODE * current);	
NODE * find_rightmost(NODE * current);

void delete_by_merge(NODE * current, NODE * previous);

void breadth_first();

NODE * search(NODE * current, int value);
void * remove_node(NODE * current);









int main(){
	  
	int i;
	int val;

	for(i = 0; i < 15; i++ ){
		scanf("%d", &val);
		add_node(val, head);
	}

	// pre_print(head); ln
	// in_print(head); ln
	// breadth_first(); ln
  breadth_first(); ln
	find_and_delete_by_merge(head, NULL, 25);
	breadth_first(); ln
	
	return 0;
}

//input: 
/* 
 25 15 50 10 22 35 70 4 12 18 24 31 44 66 90  
  15 4 20 17 19
*/







void pre_print(NODE * current){
	NODE * tmp = current;
	printf("%d -> ", (*tmp).value);
	if((*tmp).left != NULL){
		pre_print((*tmp).left);
	}
	if((*tmp).right != NULL){
		pre_print((*tmp).right);
	}
} 

void in_print(NODE * current){
	NODE * tmp = current;
	if((*tmp).left != NULL){
		in_print((*tmp).left);
	}
	printf("%d -> ", (*tmp).value);
	if((*tmp).right != NULL){
		in_print((*tmp).right);
	}
} 

void post_print(NODE * current){
	NODE * tmp = current;
	if((*tmp).left != NULL){
		post_print((*tmp).left);
	}
	if((*tmp).right != NULL){
		post_print((*tmp).right);
	}
	printf("%d -> ", (*tmp).value);
} 


NODE * create_node(char value){
	NODE * leaf = (NODE *) malloc(sizeof (NODE));
	(*leaf).value = value;    
	return leaf;
}

void * remove_node(NODE * current){
	NODE * rightmost = find_rightmost((*current).left);
	int tmp = (*rightmost).value;
	(*current).value = (*rightmost).value;
	find_and_delete_by_merge((*current).left, current, tmp);
}


void find_and_delete_by_merge(NODE * current, NODE * previous, int value){
	
	if((*head).value == value){
		NODE * rightmost = find_rightmost((*current).left);
		int tmp = (*rightmost).value;
		(*current).value = (*rightmost).value;
	  find_and_delete_by_merge((*current).left, current, tmp);
		return;
	}

	if((*current).value == value){		
		delete_by_merge(current, previous);
	}	
	NODE * tmp = current;
	if((*tmp).left != NULL){
		find_and_delete_by_merge((*tmp).left, tmp, value);
	}
	if((*tmp).right != NULL){
		find_and_delete_by_merge((*tmp).right, tmp, value);
	}	
}

NODE * delete_previous(NODE * current, NODE * previous, int value){				
    if((*current).value == value){				
      delete_by_merge(current, previous); 			
    }		
    if ((*current).left != NULL){			
        delete_previous((*current).left, current, value);
    }
    if((*current).right != NULL){
        delete_previous((*current).right, current, value);
    }       
		
}

void add_node(char value, NODE * current){
	NODE * tmp = current;

	if(current == NULL){
		head = create_node(value); 
		return;
	}

	if(value > (*tmp).value){
		if((*tmp).right == NULL){
			(*tmp).right = create_node(value);
			return;
		}
		add_node(value, (*tmp).right);
	}else {
		if((*tmp).left == NULL){
			(*tmp).left = create_node(value);
			return;
		}
		add_node(value, (*tmp).left);
	}
}	




void remove_node_with_one_orphan(NODE * current, NODE * children, NODE * previous){
	if(are_children_null(children)){
		if((*(*previous).left).value == (*current).value){					
			(*previous).left = children;
		}
		else if((*(*previous).right).value == (*current).value){
			(*previous).right = children;
		}
	}
}


bool are_children_null(NODE * current){	
	return (*current).left == NULL && (*current).right == NULL ? true : false;
}

NODE * find_rightmost(NODE * current){
	while((*current).right != NULL){
		 current = (*current).right;
	}	
	return current;
}

void breadth_first(){
    
	NODE * tmp = head;
	
	if(tmp != NULL){
		enqueue(head);
		while(!isQueueEmpty()){
			tmp = (*dequeue()).node;
			printf("%d -> ", (*tmp).value);  					      
			if((*tmp).left != NULL){
					enqueue((*tmp).left);
			}
			if((*tmp).right != NULL){
					enqueue((*tmp).right);         
			}
		}
	}
    
}

void delete_by_merge(NODE * current, NODE * previous){
	//deleting the node when there is no leaf
	if(are_children_null(current)){		
		//check if the node that will be deleted is the left one
		if((*(*previous).left).value == (*current).value){				   
				(*previous).left = NULL;
				return;
		}
		//otherwise is the right one
		else{
				(*previous).right = NULL;
				return;
		}		
	}

	//deleting the node when there is at least one leaf 	
	if((*(*previous).left).value == (*current).value){					
		if((*current).left != NULL && (*current).right == NULL){				
				remove_node_with_one_orphan(current, (*current).left, previous);
				return;
		}
		if((*current).left == NULL && (*current).right != NULL){					
				remove_node_with_one_orphan(current, (*current).right, previous);
				return;
		}
	}		
	else if ((*(*previous).right).value == (*current).value){				
	 	if((*current).left != NULL && (*current).right == NULL){			
	 			remove_node_with_one_orphan(current, (*current).left, previous);
				return;
	 	}
		if((*current).right != NULL && (*current).left == NULL){			
				remove_node_with_one_orphan(current, (*current).right, previous);
				return;
		}		
	} 	

	/* 
		find in the left subtree the node with that have the greater key 
		make this node the parent of the right subtree symmetrically, 
		the node with the lowest key can found in the right subtree 
		can be	made a parent in the left subtree.
	*/
	

	//TODO improve logic and create a method to not duplicate code on here
	if((*(*previous).left).value == (*current).value){		
		if((*current).left != NULL){		
			remove_node(current);
		  return;
		}				
	}

	if((*(*previous).right).value == (*current).value){
		if((*current).right != NULL){
			remove_node(current);
			return;
		}				
	}


}

NODE * search(NODE * current, int value){
    
    if((*current).value == value){
        return current;
    }
    if (value < (*current).value && (*current).left != NULL){
        search((*current).left, value);
    }
    if((*current).right != NULL){
        search((*current).right, value);
    }       
}






