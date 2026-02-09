#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int p, s;
}Food;

int T, N;
Food list[1005];
int DP[101005];

int Compare(const void* a, const void* b){
    Food* pa = (Food*)a;
    Food* pb = (Food*)b;
    int sum_a = (pa->p+pa->s);
    int sum_b = (pb->p+pb->s);
    if(sum_a>sum_b) return 1;
    if(sum_a<sum_b) return -1;
    return 0; 
}

int main(void){
    scanf("%d", &T);
    int n=1;
    while(n<=T){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d %d", &list[i].p, &list[i].s);
        }
        qsort(list, N, sizeof(Food), Compare);
        memset(DP, 0, sizeof(DP));

        DP[0] = 1;
        for(int i=0; i<N; i++){
            for(int j=101000; j>=0; j--){
                if(DP[j] == 1){
                    if(j<=list[i].p){
                        int temp = j+list[i].s;
                        if(temp<=101000){
                            DP[temp] = 1;
                        }
                    }
                }
            }
        }

        for(int i=101000; i>=0; i--){
            if(DP[i] == 1){
                printf("Case #%d: %d\n", n, i);
                break;
            }
        }
        n++;
    }
}
