#include <stdio.h>

int N, K;
int origin[105];
int C[105];
int list[105][105] = {0};
int Used[105] = {0}, count = 0;
int curr_C[105] = {0};

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=1; i<=K; i++){
        int temp;
        scanf("%d", &temp);
        origin[i] = temp;
        C[temp]++;
        list[temp][C[temp]] = i;
    }
    
    int ans = 0;
    for(int i=1; i<=K; i++){
        if(count<N){
            if(Used[origin[i]] == 0){
                count++;
                Used[origin[i]] = 1;
            }
            curr_C[origin[i]]++;
        }
        else{
            if(Used[origin[i]] == 1){
                curr_C[origin[i]]++;
            }
            else{
                int max = 0, selected = 0;
                for(int j=1; j<=K; j++){
                    if(Used[j] == 1){
                        if(list[j][curr_C[j]+1]== 0){
                            selected = j;
                            break;
                        }
                        else if(list[j][curr_C[j]+1]>max){
                            max = list[j][curr_C[j]+1];
                            selected = j;
                        }
                    }
                }
                Used[selected] = 0;
                Used[origin[i]] = 1;
                curr_C[origin[i]]++;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}