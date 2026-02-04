#include <stdio.h>
#include <stdlib.h>

int N, Max = 0;
typedef struct{
    int s, t;
}Class;

typedef struct{
    Class* list;
    int Capacity;
    int UsedSize;
}Heap;

Heap* createHeap(int Capacity){
    Heap* newH = (Heap*)malloc(sizeof(Heap));
    newH->list = (Class*)malloc(sizeof(Class)*(Capacity+5));
    newH->Capacity = Capacity;
    newH->UsedSize = 0;
    return newH;
}

void HeapSwap(Heap* H, int currentindex, int parentindex){
    Class temp = H->list[currentindex];
    H->list[currentindex] = H->list[parentindex];
    H->list[parentindex] = temp;
}

void InsertHeap(Heap* H, Class curr){
    int currentindex = H->UsedSize;
    int parentindex = (currentindex-1)/2;
    H->list[currentindex] = curr;
    while(currentindex>0 && H->list[currentindex].t<H->list[parentindex].t){
        HeapSwap(H, currentindex, parentindex);
        currentindex = parentindex;
        parentindex = (currentindex-1)/2;
    }
    H->UsedSize++;
}

void Pop(Heap* H){
    int parentindex = 0;
    int leftchild = 1;
    int rightchild = 2;
    H->UsedSize--;
    HeapSwap(H, 0, H->UsedSize);
    while(1){
        int selectchild = 0;
        if(leftchild>=H->UsedSize) break;
        else if(rightchild>=H->UsedSize) selectchild = leftchild;
        else if(H->list[leftchild].t<H->list[rightchild].t) selectchild = leftchild;
        else selectchild = rightchild;

        if(H->list[parentindex].t>H->list[selectchild].t){
            HeapSwap(H, parentindex, selectchild);
            parentindex = selectchild;
            leftchild = (parentindex*2)+1;
            rightchild = leftchild+1;
        }
        else break;
    }
}

Class C[200005];

int Compare(const void* a, const void* b){
    Class* pa = (Class*)a;
    Class* pb = (Class*)b;
    return pa->s - pb->s;
}

int main(void){
    scanf("%d", &N);
    Heap* H = createHeap(N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &C[i].s, &C[i].t);
    }

    qsort(C, N, sizeof(Class), Compare);

    InsertHeap(H, C[0]);
    for(int i=1; i<N; i++){
        if(H->list[0].t>C[i].s){
            InsertHeap(H, C[i]);
        }
        else{
            Pop(H);
            InsertHeap(H, C[i]);
        }
    }

    printf("%d\n", H->UsedSize);
    free(H->list);
    free(H);
    return 0;
}