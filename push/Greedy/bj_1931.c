#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int s;
    int e;
}Time;

int N;
Time list[100000];

int Compare(const void* a, const void* b){
    const Time* pa = (Time*)a;
    const Time* pb = (Time*)b;
    // if(pa->duration < pb->duration){
    //     return -1;
    // }
    // else if(pa->duration == pb->duration){
    //     if(pa->s < pb->s){
    //         return -1;
    //     }
    // }
    // return 1;

    if(pa->e != pb->e){
        return pa->e - pb->e;
    }
    return pa->s - pb->s;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        list[i] = (Time){a, b};
    }

    qsort(list, N, sizeof(Time), Compare);

    int count = 0, Max_e = 0;

    for(int i=0; i<N; i++){
        if(list[i].s>=Max_e){
            count++;
            Max_e = list[i].e;
        }
    }

    printf("%d\n", count);
    return 0;
}