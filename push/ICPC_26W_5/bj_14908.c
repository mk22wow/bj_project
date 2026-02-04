#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int t, s, idx;
}Shoe;

int N;
Shoe list[1005];

int Compare(const void* a, const void* b){
    Shoe* pa = (Shoe*)a;
    Shoe* pb = (Shoe*)b;
    int temp = pa->t*pb->s - pa->s*pb->t;
    if(temp>0) return 1;
    else if(temp == 0 && pa->idx>pb->idx) return 1;
    else return -1;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &list[i].t, &list[i].s);
        list[i].idx = i+1;
    }

    qsort(list, N, sizeof(Shoe), Compare);

    for(int i=0; i<N; i++){
        printf("%d ", list[i].idx);
    }
    return 0;
}