#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define ln printf("\n");
#define psize 15

typedef struct node{
    int value;
	struct node* left;
	struct node* right;
}NODE;

NODE * head = NULL;



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

void breadth_first(NODE * current){
    printf("%d -> ", (*current).value);  
    if((*current).left != NULL){
        breadth_first((*current).left);
    }
    if((*current).right != NULL){
        breadth_first((*current).right);
    }
}


NODE * search(NODE * current, char value){
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
	int inp;
	int i;
    
	
	for(i=0; i < psize; i++){
        scanf("%d", &inp);
		add_node(inp, head);
	}
	
	in_print(head);
	ln
	pre_print(head);
    ln
    post_print(head);
    ln    
	
	
	return 0;
}

//input: 
/* 
 25 15 50 10 22 35 70 4 12 18 24 31 44 66 90  
*/
