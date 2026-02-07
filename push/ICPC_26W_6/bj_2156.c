#include <stdio.h>

int n;
int list[10005];
int DP[3] ={0};
int curr[3] = {0};

int Max(int curr[]){
    int ans = 0;
    for(int i=0; i<3; i++){
        if(ans<curr[i]) ans = curr[i];
    }
    return ans;
}

int main(void){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &list[i]);
    }

    DP[0] = 0;
    DP[1] = list[0];
    DP[2] = 0;
    for(int i=1; i<n; i++){
        int temp_m = Max(DP);
        curr[0] = DP[0];
        curr[1] = DP[1];
        curr[2] = DP[2]; 
        DP[0] = temp_m;
        DP[1] = curr[0] + list[i];
        DP[2] = curr[1] + list[i];
    }
    
    int ans = Max(DP);
    printf("%d\n", ans);
}