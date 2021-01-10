#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <limits>

using namespace std;

typedef struct node{
  int dest;
  int weight;   
} NODE;


class Graph{
  int vertexCount;
  list<NODE> * adjList;

  private:
    void printList(int src, list<NODE> nodes){
      list<NODE> :: iterator it;
      NODE tmp;

      for(it = nodes.begin(); it != nodes.end(); it++){
        tmp = *it;
        cout << "src: " << src << " dest: " << tmp.dest << " | "<< tmp.weight;
      }
      cout << endl;
    }

  public:
    Graph() {
      vertexCount = 0;
    }

    Graph(int nodes) {
        vertexCount = nodes;
        adjList = new list<NODE>[vertexCount];
    }

    void addEdge(int src, int dest, int weight) {
        NODE node;
        node.dest = dest;
        node.weight = weight;
        adjList[src].push_back(node);
    }

    void displayEdges() {
        for(int i = 0; i< vertexCount; i++) {
          list<NODE> tmpList = adjList[i];
          printList(i, tmpList);
        }
    }

    friend void dijkstra(Graph graph, int * distance, int * previous, int start);

};

void dijkstra(Graph graph, int * distance, int * previous, int s) {
   int n = graph.vertexCount;

  for(int i = 0; i< n; i++) {
    distance[i] = INT32_MAX;   
    previous[i] = INT32_MIN;    
  }

  distance[s] = 0;   //starting distance is 0

  set<int> visited;       
  list<int> queue;

  for(int i = 0; i < n; i++) {
    queue.push_back(i);    //add each node into queue
  }

  while(!queue.empty()) {
    list<int> :: iterator i;
    i = min_element(queue.begin(), queue.end()); //get the min element from the queue
    int min_el = *i; 
    queue.remove(min_el);
    visited.insert(min_el); //add min_el in the set of visited nodes

    list<NODE> :: iterator it;

    for(it = graph.adjList[min_el].begin(); it != graph.adjList[min_el].end(); it++) {

      if((distance[min_el]+((*it).weight)) < distance[(*it).dest]) {
        distance[(*it).dest] = (distance[min_el]+((*it).weight));
        previous[(*it).dest] = min_el;
      }

    }  
  }
}







int main(){
  int n = 6;
  Graph graph(n);
  int distance[n], previous[n];
  int s = 0;

  graph.addEdge(0, 1, 4);    
  graph.addEdge(0, 2, 4);    
  graph.addEdge(1, 2, 2); 
  graph.addEdge(2, 3, 3); 
  graph.addEdge(2, 4, 6); 
  graph.addEdge(2, 5, 1); 
  graph.addEdge(3, 4, 2); 
  graph.addEdge(5, 4, 3); 

  


  dijkstra(graph, distance, previous, s);

  for(int i = 0; i < n; i++){
    if(i != s){
        cout << s << " to "; 
        cout << i << " cost: ";
        cout << distance[i] << " previous: " << previous[i] << endl;
    }
  }
  return 0;
}