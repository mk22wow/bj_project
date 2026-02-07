#include <stdio.h>
#include <limits.h>

int n, m;
int name[1002];
int DP[1002] = {0};

int main(void){
    if(scanf("%d %d", &n, &m) !=  2) return 0;

    for(int i=0; i<n; i++){
        scanf("%d", &name[i]);
    }

    DP[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        int min = INT_MAX;
        int rest = name[i], j = i;
        while(rest<=m){
            if(j == n-1){
                min = 0; 
                break;
            }
            int temp = (m-rest)*(m-rest) + DP[j+1];
            if(min>temp) min = temp; 
            rest += name[++j] + 1;
        }
        DP[i] = min;
    }

    printf("%d\n", DP[0]);
    return 0;
}