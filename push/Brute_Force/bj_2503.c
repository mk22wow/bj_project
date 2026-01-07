#include <stdio.h>

int main(void){
    int N, index = 0;
    int list[100][3];
    int result[1000] = {0};
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            for(int k=1; k<=9; k++){
                if(i!=j && j!=k && i!=k){
                    result[index++] = 100*i + 10*j + k;
                }
            }
        }
    }
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &list[i][0], &list[i][1], &list[i][2]);
        int N1 = list[i][0] / 100;
        int N2 = (list[i][0] % 100) / 10;
        int N3 = list[i][0] % 10;
        for(int j=0; j<index; j++){
            if(result[j]!=0){
                int temp_s = 0, temp_b = 0;
                int temp_1 = result[j] / 100;
                int temp_2 = (result[j] % 100) / 10;
                int temp_3 = result[j] % 10;
                if(temp_1 == N1){
                    temp_s++;
                }
                else if(temp_1 == N2 || temp_1 == N3){
                    temp_b++;
                }
                if(temp_2 == N2){
                    temp_s++;
                }
                else if(temp_2 == N1 || temp_2 == N3){
                    temp_b++;
                }
                if(temp_3 == N3){
                    temp_s++;
                }
                else if(temp_3 == N2 || temp_3 == N1){
                    temp_b++;
                }

                if(temp_s == list[i][1] && temp_b == list[i][2]){
                    continue;
                }
                else{
                    result[j] = 0;
                }
            }
        }
    }
    int count = 0;
    for(int j=0; j<index; j++){
        if(result[j]>0){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}