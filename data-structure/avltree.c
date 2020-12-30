#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ln printf("\n");
#define psize 15

static const int IMBALANCE = 1;


// **************** operations *******************
// void insert(n)         --> insert node n
// void remove(n)         --> removes node n
// bool contains(n)       --> returns true if n exsits                //TODO
// NODE findMin()         --> returns the smallest node
// NODE findMax()         --> returns the largest node
// bool isEmpty()         --> returns true if there is no root node   //TODO
// void deleteTree()      --> delete all nodes                        //TODO 
// void printTree()       --> print tree                              
// ******************ERRORS********************************


typedef struct node{
  int val;
  struct node * left;
  struct node * right;
  int height;
}NODE;

NODE * head = NULL;
typedef enum {false, true} bool;

int max(int a, int b) { return a > b ? a : b; }

int height(NODE * l){
  return l == NULL ? -1 : (*l).height;
}

NODE * create(int value){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).val = value;
  (*tmp).left = NULL;
  (*tmp).right = NULL;
  (*tmp).height = 0;
  return tmp;
}


void post_print(NODE * node){
	NODE * tmp = node;
	if((*tmp).left != NULL){
		post_print((*tmp).left);
	}
	printf("[%d,%d]", (*tmp).val, (*tmp).height);
	if((*tmp).right != NULL){
		post_print((*tmp).right);
	}
} 

void print_node(NODE * node){
  if(node != NULL){
    printf("val: %d", (*node).val);
    printf(" rig: %d", (*node).right == NULL ? -1 : (*(*node).right).val);
    printf(" left: %d\n", (*node).left == NULL ? -1 : (*(*node).left).val);
    return;
  }
  printf("- NULL -");
}

void rotate_with_right_child(NODE * node){
  NODE * right_child = (*node).right;
  (*node).right = (*right_child).left;
  (*right_child).left = node;  
  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  (*right_child).height = max(height((*right_child).right),(*node).height) + 1;  
  node = right_child;
}

void rotate_with_left_child(NODE * node ){
  NODE * left_child = (*node).left;
  (*node).left = (*left_child).right;
  (*left_child).right = node;
  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  (*left_child).height = max(height((*left_child).left),(*node).height) + 1;
  node = left_child;
}

void double_with_left_child(NODE * node){
  rotate_with_right_child((*node).left);
  rotate_with_left_child(node);
}

void double_with_right_child(NODE * node){
  rotate_with_left_child((*node).right);
  rotate_with_right_child(node);
}



void balance(NODE * node){
  
  if(node == NULL){    
    return;
  }

  if(height((*node).left) - height((*node).right) > IMBALANCE){
      if(height((*(*node).left).left) >= height((*(*node).left).right)){    
        printf("\ntentou rodar o %d com esquerdinha\n", (*node).val);    
        rotate_with_left_child(node);
      }
      else{        
        printf("\ntentou rodar o %d double com esquerdinha\n", (*node).val);
        double_with_left_child(node);
      }
  }

  else if(height((*node).right) - height((*node).left) > IMBALANCE){
        if(height((*(*node).right).right) >= height((*(*node).right).left)){
          printf("\ntentou rodar o %d com direitinha\n", (*node).val);
          rotate_with_right_child(node);
        }
        else{
          printf("\ntentou rodar o %d double com direitinha\n", (*node).val);
          double_with_right_child(node);
        }
  }

  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  printf("\nh: %d", (*node).height);

}

//TODO test the smallest
NODE * find_min(NODE * node){
  if(node == NULL){
    return node;
  } 
  if((*node).left == NULL){
    return node;
  }
  return find_min((*node).left);
}

NODE * find_max(NODE * node){
  //TODO find the largest element
}

void insert(int value, NODE * node){  
  
	if(node == NULL){
		node = head = create(value); 
	}  
  else if(value > (*node).val){
		if((*node).right == NULL){
			(*node).right = create(value);			
		}else{
		  insert(value, (*node).right);
    }
	}else {
		if((*node).left == NULL){
			(*node).left = create(value);			
		}
    else{
		  insert(value, (*node).left);
    }
	}

  balance(node);

}



int main(){
	  
	int i;
	int val;
  int n = 3;

	for(i = 0; i < n; i++ ){
		scanf("%d", &val);    
    //TODO the reference to the node after rotation is being lost
		insert(val, head);
    //post_print (head); ln 
	}
	
  
	
	return 0;
}


//input: 
/* 
 25 15 50 10 22 35 70 4 12 18 24 31 44 66 90  
  15 4 20 17 19\
avl:
  4 2 6 1 3 5 7 16 15
*/

