#include <stdio.h>
// #include <string.h>
// #include <math.h>

#define MAXm 200005
#define MAXlog 20

int m, Q;
int list[MAXm][MAXlog] = {0};

// int LOG(int n){
//     int count = 0;
//     while(n/2 != 0){
//         n/=2;
//         count++;
//     }
//     return count;
// }

int main(void){
    scanf("%d", &m);
    // memset(list, -1, sizeof(list));
    for(int i=1; i<=m; i++){
        scanf("%d", &list[i][0]);
    }
    for(int i=1; i<MAXlog; i++){
        for(int j=1; j<=m; j++){
            list[j][i] = list[list[j][i-1]][i-1]; 
        }
    }
    
    scanf("%d", &Q);
    while(Q--){
        int n, x;
        if(scanf("%d %d", &n, &x)!=2) return 0;
        // while(n!=0){
        //     int max = LOG(n);
        //     n -= pow(2,max);
        //     x = list[x][max]; 
        // }
        for(int i=MAXlog-1; i>=0; i--){
            if(n&(1<<i)){
                x = list[x][i];
                if(x == 0) break;
            }
        }
        printf("%d\n", x);
    }
    return 0;
}