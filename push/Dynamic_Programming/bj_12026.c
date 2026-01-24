#include <stdio.h>
#include <limits.h>

int N;
char str[1001];
int Dp[1001] = {0};

int main(void){
    scanf("%d %s", &N, str);
    Dp[0] = 1;
    for(int i=1; i<N; i++){
        if(str[i] == 'B'){
            int temp_i = i-1, min = INT_MAX;
            while(temp_i>=0){
                if(str[temp_i] == 'J' && Dp[temp_i] != 0){
                    int curr = Dp[temp_i]+(i-temp_i)*(i-temp_i);
                    if(min>curr){
                        min = curr;
                        Dp[i] = curr;
                    }
                }
                temp_i--;
            }
        }
        else if(str[i] == 'O'){
            int temp_i = i-1, min = INT_MAX;
            while(temp_i>=0){
                if(str[temp_i] == 'B' && Dp[temp_i] != 0){
                    int curr = Dp[temp_i]+(i-temp_i)*(i-temp_i);
                    if(min>curr){
                        min = curr;
                        Dp[i] = curr;
                    }
                }
                temp_i--;
            }
        }
        else{
            int temp_i = i-1, min = INT_MAX;
            while(temp_i>=0){
                if(str[temp_i] == 'O' && Dp[temp_i] != 0){
                    int curr = Dp[temp_i]+(i-temp_i)*(i-temp_i);
                    if(min>curr){
                        min = curr;
                        Dp[i] = curr;
                    }
                }
                temp_i--;
            }
        }
    }

    if(Dp[N-1] == 0){
        printf("-1\n");
    }
    else printf("%d\n", Dp[N-1]-1);

    return 0;
}