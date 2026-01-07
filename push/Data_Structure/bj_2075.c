#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000000

typedef struct HeapNode{
    int data;
}HeapNode;

typedef struct Heap{
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
}Heap;

Heap* CreateHeap(int Capacity){
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode)*Capacity);
    newHeap->Capacity = Capacity;
    newHeap->UsedSize = 0;
    return newHeap;
}

void DestroyHeap(Heap* H){
    free(H->Nodes);
    free(H);
}

void HeapSwap(Heap* H, int currentindex, int parentindex){
    int temp = H->Nodes[parentindex].data;
    H->Nodes[parentindex].data = H->Nodes[currentindex].data;
    H->Nodes[currentindex].data = temp;

    // HeapNode* temp = (HeapNode*)malloc(sizeof(HeapNode));
    // memcpy(temp, &H->Nodes[currentindex], sizeof(HeapNode));
    // memcpy(&H->Nodes[currentindex], &H->Nodes[parentindex], sizeof(HeapNode));
    // memcpy(&H->Nodes[parentindex], temp, sizeof(HeapNode));
    // free(temp);
}

void HeapFind(Heap* H, HeapNode* Root, int count, int num){
    int parentindex = 0;
    int leftindex;
    int rightindex;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    if(count == num){
        printf("%d\n",Root->data);
    }
    memset(&H->Nodes[0], 0, sizeof(HeapNode));
    H->UsedSize--;
    HeapSwap(H, 0, H->UsedSize);

    leftindex = 1;
    rightindex = 2;

    while(1){
        int selectchild = 0;
        if(leftindex>=H->UsedSize){
            break;
        }
        if(rightindex>=H->UsedSize){
            selectchild = leftindex;
        }
        else{
            if(H->Nodes[leftindex].data<H->Nodes[rightindex].data){
                selectchild = rightindex;
            }
            else{
                selectchild = leftindex;
            }
        }

        if(H->Nodes[parentindex].data < H->Nodes[selectchild].data){
            HeapSwap(H, parentindex, selectchild);
        }
        else{
            break;
        }
        parentindex = selectchild;
        leftindex = 2*parentindex+1;
        rightindex = leftindex+1;
    }
}

void InsertHeap(Heap* H, int data){
    int currentindex = H->UsedSize;
    int parentindex = (currentindex-1)/2;
    
    if(H->UsedSize == H->Capacity){
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode)*H->Capacity);
    }

    H->Nodes[currentindex].data = data;

    while(currentindex>0 && H->Nodes[currentindex].data > H->Nodes[parentindex].data){
        HeapSwap(H, currentindex, parentindex);
        currentindex = parentindex;
        parentindex = (currentindex-1)/2;
    }

    H->UsedSize++;
}

int main(void){
    int num = 0, i = 0;
    scanf("%d", &num);
    Heap* H = CreateHeap(num*num);
    HeapNode Node;
    for(i = 0; i<num; i++){
        for(int j=0; j<num; j++){
            int input = 0;
            scanf("%d", &input);
            if(abs(input)<=MAX_INPUT){
                InsertHeap(H, input);    
            }
        }
    }

    for(i=1; i<=num; i++){
        HeapFind(H, &Node, i, num);
    }

    DestroyHeap(H);
    return 0;
}