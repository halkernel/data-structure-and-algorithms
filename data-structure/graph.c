#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "priority-queue.h"

#define ln printf("\n");
#define psize 15



typedef struct graph{
  int vertexCount;  
  int * visited;
  NODE ** adjList;
}GRAPH;

NODE * create_node(int vertex, int weight){
  NODE * tmp = (NODE * ) malloc (sizeof ( NODE ) );
  (*tmp).vertex = vertex;
  (*tmp).weight = weight;
  (*tmp).next = NULL;
  return tmp;
}


GRAPH * create_graph(int vertexCount){  
  GRAPH * graph = (GRAPH *) malloc(sizeof(GRAPH));   
  (*graph).vertexCount = vertexCount;
  (*graph).adjList = malloc(vertexCount * sizeof(NODE *));

  int i = 0;  
  for(; i < vertexCount; i++){
    (*graph).adjList[i] = NULL;
  }
  return graph;
}

void insert_edge(GRAPH * graph, int src, int dest, int weight){
  //add edge from src to dest
  NODE * tmp = create_node(dest, weight);
  (*tmp).next = (*graph).adjList[src];
  (*graph).adjList[src] = tmp;

  //add edge from dest to src

  // tmp = create_node(src, weight);
  // (*tmp).next = (*graph).adjList[dest];
  // (*graph).adjList[dest] = tmp;
}

void print_graph(GRAPH * graph){
  int i;
  for(i = 0; i < (*graph).vertexCount; i++){
    NODE * tmp = (*graph).adjList[i];
    printf("\nvertex %d:\n", i);
    while (tmp != NULL){    
      printf("[w:%d] %d -> ", (*tmp).weight, (*tmp).vertex);
      tmp = (*tmp).next;
    }    
  }
}

void dijkstra(GRAPH * graph){
  int i;
  for(i = 0; i < (*graph).vertexCount; i++){
    //INT_MIN
  }
}


int main(){	  

	GRAPH * graph = create_graph(3);

  insert_edge(graph, 0, 1, 1);
  
  //insert_edge(graph, 0, 2);
  //insert_edge(graph, 0, 3);
  //insert_edge(graph, 1, 2);

  print_graph(graph);
  

	return 0;
}

