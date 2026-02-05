#include <stdio.h>
#include <stdlib.h>

int C, N, count = 0;
int cow[20005][2];
int chick[20005];

int Compare1(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int Compare2(const void* a, const void* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return pa[0] - pb[0];
}

typedef struct{
    int s;
    int e;
}Pair;

Pair Q[20005];
int top = -1;

void Insert(int s, int e){
    Q[++top] = (Pair){s, e};
    int child = top;
    int parent = (top-1)/2;
    while(parent>=0){
        if(Q[child].e<Q[parent].e){
            Pair temp = Q[child];
            Q[child] = Q[parent];
            Q[parent] = temp;
            child = parent;
            parent = (child-1)/2;
        }
        else break;
    }
}

void Pop(){
    if(top == 0){
        top--;
        return;
    }
    else{
        Q[0] = Q[top--];
        int parent = 0;
        int left = 1, right = 2, select;

        while(1){
            if(left>top) return;
            else if(right>top) select = left;
            else if(Q[left].e<Q[right].e) select = left;
            else select = right;

            if(Q[parent].e>Q[select].e){
                Pair temp = Q[parent];
                Q[parent] = Q[select];
                Q[select] = temp;
                parent = select;
                left = (parent*2)+1;
                right = left+1;
            }
            else return;
        }
    }

}

int main(void){
    scanf("%d %d", &C, &N);
    for(int i=0; i<C; i++){
        scanf("%d", &chick[i]);
    }

    for(int i=0; i<N; i++){
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }

    qsort(chick, C, sizeof(int), Compare1);
    qsort(cow, N, sizeof(cow[0]), Compare2);

    int idx = 0;
    for(int i=0; i<C; i++){
        while(idx<N && chick[i]>=cow[idx][0]){
            Insert(cow[idx][0], cow[idx][1]);
            idx++;
        }
        while(top>=0 && chick[i]>Q[0].e){
            Pop();
        }
        if(top>=0){
            Pop();
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}