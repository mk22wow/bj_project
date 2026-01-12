#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N, K;
int list[300000];
int distance[300000];
int Min = INT_MAX;

// void Find(int s, int e, int count, int price){
//     price += list[e] - list[s];
//     count++;
//     if(count == K){
//         if(Min>price){
//             Min = price;
//         }
//         return;
//     }
//     int k = K-count;
//     if(k == 1){
//         Find(e+1, N-1, count, price);
//     }
//     else{
//         for(int i=N-k; i>=e+1; i--){
//             Find(e+1, i, count, price);
//         }
//     }
// }

int Compare(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    scanf("%d %d", &N, &K);
    int result = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        if(i!=0){
            distance[i-1] = list[i] - list[i-1];
            result += distance[i-1];
        }
    }

    // for(int i=0; i<N-K; i++){
    //     Find(0, i, 0, 0);
    // }

    qsort(distance, N-1, sizeof(int), Compare);
    for(int i=0; i<K-1; i++){
        result -= distance[i];
    }
    printf("%d\n", result);
    return 0;
}