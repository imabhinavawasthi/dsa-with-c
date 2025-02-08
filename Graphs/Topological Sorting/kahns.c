// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
}

// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}


void topologicalSort(struct Graph* graph) {
    int n = graph->numVertices;

    // queue
    struct queue* q = createQueue();

    int indegree[n];
    int topological[n];
    int count = 0;
    for(int i=0;i<n;i++)indegree[i]=0;

    for(int i=0;i<n;i++){
        struct node* temp = graph->adjLists[i];

        while (temp!=NULL) {
            int adjVertex = temp->vertex;
            indegree[adjVertex]++;
            temp=temp->next;
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==0) {
            enqueue(q,i);
        }
    }

    while(!isEmpty(q)) {
        int front = dequeue(q);
        topological[count]=front;
        count++;

        struct node* temp = graph->adjLists[front];

        while (temp!=NULL) {
            int adjVertex = temp->vertex;
            indegree[adjVertex]--;
            if(indegree[adjVertex]==0){
                enqueue(q,adjVertex);
            }
            temp=temp->next;
        }
    }
    if(count==n){
        for(int i=0;i<n;i++){
            printf("%d, ",topological[i]);
        }
    }
    else{
        printf("Not Possible");
    }
}

int main() {
  int n = 6;
  struct Graph* graph = createAGraph(n);
  addEdge(graph, 5, 0);
  addEdge(graph, 4, 0);
  addEdge(graph, 5, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 1);
  addEdge(graph, 4, 1);
//   addEdge(graph, 1, 2); if we will add this edge, it's not possible

  topologicalSort(graph);

  return 0;
}