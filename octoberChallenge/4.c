#include<stdio.h>
#include<stdlib.h>

struct nodeLinkedList {
long int nValue;
char color;
struct nodeLinkedList *path;
};
void mergeSort (struct nodeLinkedList **startNode);
void splitUni (struct nodeLinkedList **node1, struct nodeLinkedList **A, struct nodeLinkedList **B);
struct nodeLinkedList * sortMerge (struct nodeLinkedList **node1, struct nodeLinkedList **node2);

int main() {
    int T;
    long int N, M, nodeValue, j;
    long long int fmul, ans;
    char nodeColor;
    scanf("%d",&T);
    while (T--) {
        scanf("%ld %ld",&N,&M);
        struct nodeLinkedList *startNode, *previousNode;
        struct nodeLinkedList *node = NULL;

        node = (struct nodeLinkedList*) malloc(sizeof(struct nodeLinkedList));
        startNode = node;

        scanf(" %c %ld",&nodeColor,&nodeValue);
        node -> nValue = nodeValue;
        node -> color = nodeColor;
        int check = 1;
        for (j=2;j<=M;j++) {
            previousNode = node;
            node = (struct nodeLinkedList*) malloc(sizeof(struct nodeLinkedList));
            scanf(" %c %ld",&nodeColor,&nodeValue);
            node -> color = nodeColor;
            node -> nValue = nodeValue;
            if (previousNode -> nValue > node ->nValue ){ check =0; }
            previousNode -> path = node;
        }
        node -> path = NULL;
        if (check == 0) mergeSort (&startNode);

        ans = 1;

        previousNode = startNode;
        node = previousNode -> path;
        while (node != NULL) {
            fmul = 1;
            if (previousNode -> color != node -> color) {
                fmul = node -> nValue - previousNode -> nValue;
            }
            ans = ans * fmul;
ans = ans % 1000000009;
            previousNode = node;
            node = node -> path;
        }

        printf("%ld\n",ans);
        node = startNode;
        while (node != NULL) {
            previousNode = node;
            node = node -> path;
            free (previousNode);
        }
    }
    return 0;
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
        if(A -> nValue <= B -> nValue) {
            fir = A;
            uni = A;
            A = A -> path;
        }
        else {
            uni = B;
            fir = B;
            B = B -> path;
        }
        while (A != NULL && B != NULL) {
            if(A -> nValue <= B -> nValue) {
                uni -> path = A;
                uni = uni -> path;
                A = A -> path;
            }
            else {
                uni -> path = B;
                uni = uni -> path;
                B = B -> path;
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
