#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct graph {
    int numVertices;
    Node **adjLists;
} Graph;

Node *createNode(int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}


void addEdge(Graph *graph, int s, int d) {
    Node *newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}





int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    Graph *g=createGraph(n+1);
    for(int i=0;i<trustSize;i++){
        addEdge(g,trust[i][0],trust[i][1]);
    }
    int judge=-1;
    for(int i=1;i<=n;i++){
        if(g->adjLists[i]==NULL){
            judge=i;
            break;
        }
    }
    if(judge==-1){
        return -1;
    }
    int count=0;
    for(int j=1;j<=n;j++){
        if(j!=judge){
            Node *temp=g->adjLists[j];
            while(temp!=NULL){
                if(temp->vertex==judge){
                    count++;
                    break;
                }
                temp=temp->next;
            }
        }
    }
    if(count==n-1){
        return judge;
    }
    return -1;
}