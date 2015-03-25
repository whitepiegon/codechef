#include<stdio.h>
#include<stdlib.h>

struct nodeLinkedList {
long int nValue;
long int yValue;
struct nodeLinkedList *path;
};
void mergeSort (struct nodeLinkedList **startNode);
void splitUni (struct nodeLinkedList **node1, struct nodeLinkedList **A, struct nodeLinkedList **B);
struct nodeLinkedList * sortMerge (struct nodeLinkedList **node1, struct nodeLinkedList **node2);
int furthercheck (struct nodeLinkedList **middleNode,struct nodeLinkedList **twiceNode, long int x, long int y);

int main() {
    int N, l, ans = 2;
    long int x, y;
    long long int distij, distik, distjk;
    scanf("%d",&N);
    if (N==0) {printf("4");return 0;}
    if (N==1) {printf("3");return 0;}
    if (N==2) {printf("2");return 0;}

    struct nodeLinkedList *startNode, *previousNode, *i, *j, *k;
    struct nodeLinkedList *node = NULL;

    node = (struct nodeLinkedList*) malloc(sizeof(struct nodeLinkedList));
    startNode = node;
    scanf("%ld %ld",&x,&y);
    node -> nValue = x;
    node -> yValue = y;
    for (l=2;l<=N;l++) {
        previousNode = node;
        node = (struct nodeLinkedList*) malloc(sizeof(struct nodeLinkedList));
        scanf("%ld %ld",&x,&y);
        node -> nValue = x;
        node -> yValue = y;
        previousNode -> path = node;
    }
    node -> path = NULL;

    mergeSort (&startNode);
    i = startNode;
    j = i -> path;
    k = j -> path;
    while (i != NULL) {
        while (j != NULL) {
            distij = ((i->nValue)-(j->nValue))*((i->nValue)-(j->nValue)) + ((i->yValue)-(j->yValue))*((i->yValue)-(j->yValue));
            while (k != NULL) {
                distik = ((i->nValue)-(k->nValue))*((i->nValue)-(k->nValue)) + ((i->yValue)-(k->yValue))*((i->yValue)-(k->yValue));
                distjk = ((j->nValue)-(k->nValue))*((j->nValue)-(k->nValue)) + ((j->yValue)-(k->yValue))*((j->yValue)-(k->yValue));
                if (distik>2*distij || distjk>2*distij) break;
                if ((((i->nValue)-(k->nValue))*((j->nValue)-(k->nValue)) + ((i->yValue)-(k->yValue))*((j->yValue)-(k->yValue))) == 0) {
                    if (distik == distjk) {
                        x = (i->nValue) + (j->nValue) - (k->nValue);
                        y = (i->yValue) + (j->yValue) - (k->yValue);
                        ans = 1;
                        ans = ans - furthercheck (&k,&(k->path),x,y);
                    }
                }
                else if ((((i->nValue)-(j->nValue))*((k->nValue)-(j->nValue)) + ((i->yValue)-(j->yValue))*((k->yValue)-(j->yValue))) == 0) {
                    if (distij == distjk) {
                        x = (i->nValue) - (j->nValue) + (k->nValue);
                        y = (i->yValue) - (j->yValue) + (k->yValue);
                        ans = 1;
                        ans = ans - furthercheck (&k,&(k->path),x,y);
                    }
                }
                else if ((((k->nValue)-(i->nValue))*((j->nValue)-(i->nValue)) + ((k->yValue)-(i->yValue))*((j->yValue)-(i->yValue))) == 0) {
                    if (distik == distij) {
                        x = (j->nValue) + (k->nValue) - (i->nValue);
                        y = (j->yValue) + (k->yValue) - (i->yValue);
                        ans = 1;
                        ans = ans - furthercheck (&k,&(k->path),x,y);
                    }
                }
                if (ans==0) break;
                k = k->path;
            }
            if (ans==0) break;
            j = j->path;
            if (j!=NULL) k = j->path;
        }
        if (ans==0) break;
        i = i->path;
        if (i!=NULL) j = i->path;
        if (j!=NULL) k = j->path;
    }
    printf("%d",ans);
    node = startNode;
    while (node != NULL) {
        previousNode = node;
        node = node -> path;
        free (previousNode);
    }
    return 0;
}
int furthercheck (struct nodeLinkedList **middleNode, struct nodeLinkedList **twiceNode, long int x, long int y) {
    struct nodeLinkedList *A, *B;
    A = *middleNode;
    if (A->path == NULL) return 0;

    B = *twiceNode;
    if (B->path != NULL) {
        B = B->path;
    }
    if (B->nValue < x || B->yValue < y) {
        if (A->path->nValue == x || A->path->yValue == y) {return 1;}
        else return 0;
        }
    else if (B->nValue == x && B->yValue == y) {return 1;}
    else return furthercheck(&B,&(B->path), x, y);
}
void mergeSort (struct nodeLinkedList **startNode) {
    struct nodeLinkedList *A, *B, *uni;
    uni = *startNode;
    if (uni -> path == NULL) return;
    splitUni (&uni, &A, &B);
    mergeSort (&A);
    mergeSort (&B);
    uni = sortMerge (&A, &B);
    *startNode = uni;
    return;
}
void splitUni (struct nodeLinkedList **node1, struct nodeLinkedList **A, struct nodeLinkedList **B) {
    struct nodeLinkedList *n1, *n2, *uni;
    uni = *node1;
    *A = uni;
    n1 = uni;
    n2 = uni;
    while (n2 -> path != NULL && n2 -> path -> path !=NULL) {
        n1 = n1 -> path;
        n2 = n2 -> path -> path;
    }
    *B = n1 -> path;
    n1 -> path = NULL;
    return;
}
struct nodeLinkedList * sortMerge (struct nodeLinkedList **node1, struct nodeLinkedList **node2) {
    struct nodeLinkedList *A, *B, *uni, *fir;
    A = *node1;
    B = *node2;
    if (A == NULL) {
        return B;
    }
    else if (B == NULL) {
        return A;
    }
    else {
        if(A -> nValue > B -> nValue) {
            fir = A;
            uni = A;
            A = A -> path;
        }
        else if (A -> nValue < B -> nValue){
            uni = B;
            fir = B;
            B = B -> path;
        }
        else {
            if(A -> yValue >= B -> yValue) {
                fir = A;
                uni = A;
                A = A -> path;
            }
            else if (A -> yValue < B -> yValue){
                uni = B;
                fir = B;
                B = B -> path;
            }
        }
        while (A != NULL && B != NULL) {
            if(A -> nValue > B -> nValue) {
                uni -> path = A;
                uni = uni -> path;
                A = A -> path;
            }
            else if(A -> nValue < B -> nValue) {
                uni -> path = B;
                uni = uni -> path;
                B = B -> path;
            }
            else {
                if(A -> yValue >= B -> yValue) {
                    uni -> path = A;
                    uni = uni -> path;
                    A = A -> path;
                }
                else if (A -> yValue < B -> yValue){
                    uni -> path = B;
                    uni = uni -> path;
                    B = B -> path;
                }
            }
        }
        if (A == NULL) {
                uni -> path = B;
                B = NULL;
        }
        else if (B == NULL) {
            uni -> path = A;
            A = NULL;
        }
    }
    *node1 = A;
    *node2 = B;
    return fir;
}
