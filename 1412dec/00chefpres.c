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
void query (int u);
struct Graph* createGraph(int V);
void addEdge(int src, int dest);

struct Graph* graph;
int aa=0, bb=0, zz[10001][3];
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
            ans=u;
        }
        aa=0, bb=0;
        struct AdjListNode* pCrawl = graph->array[u].head;

        while (pCrawl) {
            zz[bb][2]=pCrawl->dest;
            zz[bb][0]=u;    zz[bb][1]=P[u];
            pCrawl = pCrawl->next;
            bb++;
        }
        while (aa!=bb  && cou<Q[v]) {
            query(v);
        }

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

void query (int v) {
	if(zz[aa][1]>P[zz[aa][2]]) zz[aa][1]=P[zz[aa][2]];
    if (A[zz[aa][2]]==v) {
    	cou++;
        if (min==-1) {
            ans = zz[aa][2];
            min=zz[aa][1];
        }
        else if (min<zz[aa][1]) {
            ans = zz[aa][2];
            min=zz[aa][1];
        }
        else if (min==zz[aa][1] && ans>zz[aa][2]) {
            ans=zz[aa][2];
        }
    }
	if (cou<Q[v]) {
        struct AdjListNode* pCrawl = graph->array[zz[aa][2]].head;
        while (pCrawl) {
            if (pCrawl->dest != zz[aa][0]) {
                zz[bb][2]=pCrawl->dest;
                zz[bb][0]=zz[aa][2];    zz[bb][1]=zz[aa][1];
                bb++;
            }
            pCrawl = pCrawl->next;
        }
	}
	aa++;
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
