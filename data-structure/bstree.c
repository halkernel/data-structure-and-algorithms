#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define ln printf("\n");
#define psize 15



NODE * head = NULL;

typedef enum {false, true} bool;



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

bool are_children_null(NODE * current){
	return (*current).left == NULL && (*current).right == NULL ? true : false;
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

	/*
			 _____15_______
		4				    _____20	
				  		17
						     19 
	*/
	//deleting the node when there is at least one leaf 
	//TODO do the right subtree also
	if((*current).left != NULL && (*current).right == NULL){
		if(are_children_null((*current).left)){
				if((*(*previous).left).value == (*current).value){					
					(*previous).left = (*current).left;
				}
				// else if((*(*previous).left).value == (*current).value){
				// 	(*previous).left = (*current).right;
				// }
		}
	}
	else if((*current).left == NULL && (*current).right != NULL){
		if(are_children_null((*current).right)){
			printf("children on right null");
		}
	}
	printf("deleting");
	/*

  ->find in the left subtree the node with that have the greater key 
	->make this node the parent of the right subtree
	-> symmetrically, the node with the lowest key can 
	found in the right subtree can be	made a parent in the left subtree.

	*/
}

void find_and_delete_by_merge(NODE * current, NODE * previous, int value){
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


void delete_by_copy(NODE * node, NODE * previous){

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


int main(){
	  
	int i;
	int val;

	for(i = 0; i < 5; i++ ){
		scanf("%d", &val);
		add_node(val, head);
	}

	// pre_print(head); ln
	// in_print(head); ln
	// post_print(head); ln
	breadth_first(); ln
	find_and_delete_by_merge(head, NULL,  17); ln
	breadth_first(); ln
	
	return 0;
}

//input: 
/* 
 25 15 50 10 22 35 70 4 12 18 24 31 44 66 90  
  15 4 20 17 19
*/

/*



*/