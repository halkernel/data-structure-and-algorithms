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



                              //50          70
void rotate_with_right_child(NODE * node, NODE * parent){
  NODE * right_child = (*node).right; // 60
  (*node).right = (*right_child).left;
  (*right_child).left = node;  
  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  (*right_child).height = max(height((*right_child).right),(*node).height) + 1;  
  if(parent == NULL){
    head = right_child;
  }else if((*(*parent).right).val == (*node).val) {
    (*parent).right = right_child;
  }  
  else{
    (*parent).left = right_child;
  }
}

                            //80         70
void rotate_with_left_child(NODE * node, NODE * parent){
  NODE * left_child = (*node).left; //72
  (*node).left = (*left_child).right;
  (*left_child).right = node;
  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  (*left_child).height = max(height((*left_child).left),(*node).height) + 1;
  if(parent == NULL){
    head = left_child;
  }else if((*(*parent).right).val == (*node).val) {
    (*parent).right = left_child;
  }  
  else{
    (*parent).left = left_child;
  } 
}

void double_with_left_child(NODE * node, NODE * parent){
  rotate_with_right_child((*node).left, node);  
  rotate_with_left_child(node, parent);
}

void double_with_right_child(NODE * node, NODE * parent){  
  rotate_with_left_child((*node).right, node);      
  rotate_with_right_child(node, parent);  
}



void balance(NODE * node, NODE * parent){
  
  if(node == NULL){    
    return;
  }  

  if(height((*node).left) - height((*node).right) > IMBALANCE){
      if(height((*(*node).left).left) >= height((*(*node).left).right)){  
        printf("lr\n");
        rotate_with_left_child(node, parent);
      }
      else{        
        printf("dlr\n");        
        double_with_left_child(node, parent);
      }
  }

  else if(height((*node).right) - height((*node).left) > IMBALANCE){
        if(height((*(*node).right).right) >= height((*(*node).right).left)){
          printf("rr\n");
          rotate_with_right_child(node, parent);
        }
        else{
          printf("drr %d\n", (*node).val);          
          double_with_right_child(node, parent);
        }
  }

  (*node).height = max(height((*node).left), height((*node).right)) + 1;

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

void insert(int value, NODE * node, NODE * parent){  
  
	if(node == NULL){
		node = head = create(value); 
	}  
  else if(value > (*node).val){
		if((*node).right == NULL){
			(*node).right = create(value);			
		}else{
		  insert(value, (*node).right, node);
    }
	}else {
		if((*node).left == NULL){
			(*node).left = create(value);			
		}
    else{
		  insert(value, (*node).left, node);
    }
	}

  balance(node, parent);

}



int main(){
	  
	int i;
	int val;
  int n = 6;

	for(i = 0; i < n; i++ ){
		scanf("%d", &val);    
    //TODO the reference to the node after rotation is being lost
		insert(val, head, NULL);
    post_print (head); ln 
	}
	//post_print (head); ln 
  
	
	return 0;
}


//input: 
/* 
rotation:
  n = 3
  1 2 3
  3 2 1
double rotation
  n = 6
  70 50 80 60 20 55
  70 50 80 72 90 75
  refference: https://www.oreilly.com/library/view/learning-javascript-data/9781788623872/08bd6916-3d47-4c85-86da-fc49ca07ddcc.xhtml
*/

