#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ln printf("\n");
#define psize 15

static const int IMBALANCE = 1;

typedef struct node{
  int val;
  struct node * left;
  struct node * right;
  int height;
}NODE;

NODE * head = NULL;
typedef enum {false, true} bool;


int height(NODE * l){
  return l == NULL ? -1 : (*l).val;
}

NODE * create(int value){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).val = value;
  (*tmp).left = NULL;
  (*tmp).right = NULL;

  return tmp;
}

void rotate_with_left_child(NODE * node){
  NODE * left_of_node = (*node).left;
  (*node).left = (*left_of_node).right;
  (*left_of_node).right = node;
  (*node).height = max(height((*node).left), height((*node).right)) + 1;
  (*left_of_node).height = max(height((*left_of_node).left),(*node).height) + 1;
  node = left_of_node;
}

void balance(NODE * node){
  
  if(node == NULL){
    return;
  }

  if(height((*node).left) - height((*node).right) > IMBALANCE){
      if(height((*(*node).left).left) >= height((*(*node).left).right)){
        rotate_with_left_child(node);
      }
      else{
        //double_with_left_child
      }
  }

  else if (height((*node).right) - height((*node).left) > IMBALANCE){
        if( height((*(*node).right).right) >= height((*(*node).right).left)){
          //rotate_with_right_child
        }
        else{
          //double_with_right_child
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

void insert(int value, NODE * node){
  NODE * tmp = node;

	if(tmp == NULL){
		head = create(value); 
		return;
	}
  
  if(value > (*tmp).val){
		if((*tmp).right == NULL){
			(*tmp).right = create(value);
			return;
		}
		insert(value, (*tmp).right);
	}else {
		if((*tmp).left == NULL){
			(*tmp).left = create(value);
			return;
		}
		insert(value, (*tmp).left);
	}

  balance(node);

}

void in_print(NODE * node){
	NODE * tmp = node;
	if((*tmp).left != NULL){
		in_print((*tmp).left);
	}
	printf("%d -> ", (*tmp).val);
	if((*tmp).right != NULL){
		in_print((*tmp).right);
	}
} 


int main(){
	  
	int i;
	int val;

	for(i = 0; i < 15; i++ ){
		scanf("%d", &val);
		insert(val, head);
	}

	in_print(head); ln
  
	
	return 0;
}


//input: 
/* 
 25 15 50 10 22 35 70 4 12 18 24 31 44 66 90  
  15 4 20 17 19
*/

