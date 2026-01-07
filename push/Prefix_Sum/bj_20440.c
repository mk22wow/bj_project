#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX 2100000000

typedef struct{
    int position;
    int data;
}Event;

int Compare(const void* a, const void* b){
    const Event* pa = (Event*)a;
    const Event* pb = (Event*)b;
    if(pa->position == pb->position){
        return pa->data - pb->data;
    }
    return pa->position - pb->position;
}

// int Compare(const void* a, const void* b){
//     return *(int*)a-*(int*)b;
// }

// void checkMax(int* list_s, int* list_e, int N){
//     int max = 0, temp = 0;
//     int index_s = 0, index_e = 0;
//     int result_s, result_e = 0;
//     for(int i=0; i<MAX+1; i++){
//         while(list_s[index_s]==i){
//             temp++;
//             index_s++;
//             if(index_s==N){
//                 break;
//             }
//         }
//         while(list_e[index_e]==i){
//             temp--;
//             index_e++;
//             if(index_e==N){
//                 break;
//             }
//         }
//         if(temp>max){
//             max = temp;
//             result_s = i;
//         }
//         if(temp<max && result_e<result_s){
//             result_e = i;
//         }
//     }
//     printf("%d\n", max);
//     printf("%d %d\n", result_s, result_e);
// }

void checkMax(Event* list, int N){
    int max = 0, in_max = 0;
    int index_s = 0, index_e = 0;
    int temp = 0;
    for(int i=0; i<N*2; i++){
        temp += list[i].data;
        if(i!=(N*2-1) && list[i].position == list[i+1].position){
            continue;
        }
        if(temp>max){
            max = temp;
            index_s = list[i].position;
            in_max = 1;
        }
        else if(temp<max && in_max){
            index_e = list[i].position;
            in_max = 0;            
        }

    }

    printf("%d\n", max);
    printf("%d %d\n", index_s, index_e);
}

int main(void){
    int N;
    scanf("%d", &N);
    if(N<1||N>1000000){
        return 0;
    }
    // int* list_s = (int*)calloc(N, sizeof(int));
    // int* list_e = (int*)calloc(N, sizeof(int));
    // int max = 0;
    // for(int i=0; i<N; i++){
    //     int E, X;
    //     scanf("%d %d", &E, &X);
    //     if(E<0 || X>MAX){
    //         free(list_s);
    //         free(list_e);
    //         return 0;
    //     }
    //     list_s[i] = E;
    //     list_e[i] = X;
    // }
    // qsort(list_s, N, sizeof(int), Compare);
    // qsort(list_e, N, sizeof(int), Compare);
    // checkMax(list_s, list_e, N);
    // free(list_s);
    // free(list_e);

    Event* list = (Event*)malloc(sizeof(Event)*N*2);
    for(int i=0; i<N; i++){
        int E, X;
        scanf("%d %d", &E, &X);
        if(E<0 || X>MAX){
            free(list);
            return 0;
        }
        Event temp_s, temp_e;
        temp_s.data = 1;
        temp_s.position = E;
        temp_e.data=-1;
        temp_e.position = X;

        list[i*2] = temp_s;
        list[i*2+1] = temp_e;
    }

    qsort(list, N*2, sizeof(Event), Compare);
    checkMax(list, N);
    free(list);
    return 0;
}