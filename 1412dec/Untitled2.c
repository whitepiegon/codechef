#include<stdio.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList* array;
};


void love(int i, int num, int parent);
void query (int u, int v, int mn, int parent);
struct Graph* createGraph(int V);
void addEdge(int src, int dest);

struct Graph* graph;
struct AdjListNode* aayu[10001][2]; int aa=0, bb=0;
int n, q, b, ans, min, cou;
int A[10001], P[10001], S[10001], Q[101];
int main() {
    int k, i, u, v;

    scanf("%d %d %d",&n,&k,&b);
    graph = createGraph(n+1);
    for (i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        addEdge(u, v);
    }

    love (0,b,0);

    for (i=1;i<=n;i++) {
        scanf("%d",&A[i]);
        Q[A[i]]++;
    }
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        scanf("%d %d",&u,&v);
        ans=-1; min=-1;
        cou=0;
        if (A[u]==v) {
        	cou++;
            ans=u; min=P[u];
            struct AdjListNode* pCrawl = graph->array[u].head;
            while (pCrawl && cou<Q[v]) {
                query(pCrawl->dest,v,P[u],u);
                pCrawl = pCrawl->next;
            }
        }
        else query(u,v,P[u],0);

        printf("%d\n",ans);
    }
    return 0;
}

void love(int i, int num, int parent) {
    S[i]=num;
    struct AdjListNode* pCrawl = graph->array[num].head;

    while (pCrawl){
        if (pCrawl->dest != parent)
        love(i+1,pCrawl->dest, num);
        pCrawl = pCrawl->next;
    }
    P[num]=i;
}

void query (int u, int v, int mn, int parent) {
    if(mn>P[u]) mn=P[u];
    if (A[u]==v) {
    	cou++;
        if (min==-1) {
            ans = u;
            min=mn;
        }
        else if (min<mn) {
            ans = u;
            min=mn;
        }
        else if (min==mn && ans>u) {
            ans=u;
        }
    }
	if (cou<Q[v]) {
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            if (pCrawl->dest != parent)
            query(pCrawl->dest,v,mn,u);
            pCrawl = pCrawl->next;
        }
	}
}

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}
void addEdge(int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
