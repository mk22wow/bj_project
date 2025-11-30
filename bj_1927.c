#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

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
    newHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode)*MAX_SIZE);
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

void HeapFind(Heap* H, HeapNode* Root){
    int parentindex = 0;
    int leftindex;
    int rightindex;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    printf("%d\n",Root->data);
    
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
            if(H->Nodes[leftindex].data>H->Nodes[rightindex].data){
                selectchild = rightindex;
            }
            else{
                selectchild = leftindex;
            }
        }

        if(H->Nodes[parentindex].data > H->Nodes[selectchild].data){
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
    
    H->Nodes[currentindex].data = data;
    while(currentindex>0 && H->Nodes[currentindex].data < H->Nodes[parentindex].data){
        HeapSwap(H, currentindex, parentindex);
        currentindex = parentindex;
        parentindex = (currentindex-1)/2;
    }

    H->UsedSize++;
}

int main(void){
    int num = 0, i = 0;
    scanf("%d", &num);
    Heap* H = CreateHeap(MAX_SIZE);
    HeapNode Node;
    while(i<num){
        int input = 0;
        scanf("%d", &input);
        if(input == 0){
            if(H->UsedSize == 0){
                printf("0\n");
            }
            else{
                HeapFind(H, &Node);
            }
        }
        else{
            InsertHeap(H, input);
        }
        i++;
    }

    DestroyHeap(H);
    return 0;
}