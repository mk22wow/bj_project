#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct HeapNode{
    int data;
}HeapNode;

typedef struct{
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
}Heap;

Heap* createHeap(int Capacity){
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
}

void HeapFind(Heap* H, HeapNode* Root){
    int parentindex = 0;
    int leftindex;
    int rightindex;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    printf("%d\n", Root->data);

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
            if(abs(H->Nodes[leftindex].data)<abs(H->Nodes[rightindex].data)){
                selectchild = leftindex;
            }
            else if(abs(H->Nodes[leftindex].data)==abs(H->Nodes[rightindex].data)){
                if(H->Nodes[leftindex].data<0){
                    selectchild = leftindex;
                }
                else{
                    selectchild = rightindex;
                }
            }
            else{
                selectchild = rightindex;
            }
        }

        if(abs(H->Nodes[parentindex].data) > abs(H->Nodes[selectchild].data) || 
        (abs(H->Nodes[parentindex].data) == abs(H->Nodes[selectchild].data) && H->Nodes[selectchild].data < 0)){
            HeapSwap(H, parentindex, selectchild);
        }
        else{
            break;
        }

        parentindex = selectchild;
        leftindex = 2*parentindex + 1;
        rightindex = 2*parentindex + 2;
    }
}

void InsertHeap(Heap* H, int data){
    int currentindex = H->UsedSize;
    int parentindex = (currentindex-1)/2;

    H->Nodes[currentindex].data = data;
    while(currentindex>0 && (abs(H->Nodes[currentindex].data) < abs(H->Nodes[parentindex].data) || 
(abs(H->Nodes[currentindex].data) == abs(H->Nodes[parentindex].data) && H->Nodes[currentindex].data<0))){
    HeapSwap(H, currentindex, parentindex);
    currentindex = parentindex;
    parentindex = (currentindex-1)/2;
}
    H->UsedSize++;
}

int main(void){
    int num, i = 0;
    scanf("%d", &num);
    Heap* H = createHeap(num);
    HeapNode Root;
    while(i<num){
        int input = 0;
        scanf("%d", &input);
        if(input == 0){
            if(H->UsedSize == 0){
                printf("0\n");
            }
            else{
                HeapFind(H, &Root);
            }
        }
        else{
            InsertHeap(H, input);
        }
        ++i;
    }

    DestroyHeap(H);
    return 0;
}