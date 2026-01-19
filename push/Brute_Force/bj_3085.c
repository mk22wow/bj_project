#include <stdio.h>

int N;
int list[50][50];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main(void){
    scanf("%d", &N);
    int Max = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            scanf(" %c", &c);
            if(c == 'C'){
                list[i][j] = 1;
            }
            else if(c == 'P') list[i][j] = 2;
            else if(c == 'Z') list[i][j] = 3;
            else list[i][j] = 4;
        }
    }

    for(int i=0; i<N; i++){ //사탕을 바꾸기 전 연속 부분 구하기
        int current = list[i][0];
        int count = 1;
        for(int j=1; j<N; j++){
            if(current!=list[i][j]){
                current = list[i][j];
                count = 1;
            }
            else {
                count++;
                if(count>Max) Max = count;
            }
        }

        current = list[0][i];
        count = 1;
        for(int j=1; j<N; j++){
            if(current!=list[j][i]){
                current = list[j][i];
                count = 1;
            }
            else {
                count++;
                if(count>Max) Max = count;
            }
        }
    }
    if(Max == N){
        printf("%d\n", Max);
        return 0;
    }

    for(int i=0; i<N; i++){ //사탕을 바꾸며 연속 부분 구하기
        for(int j=0; j<N; j++){
            for(int k=0; k<2; k++){
                int x = j + dx[k];
                int y = i + dy[k];
                if(x>=N || y>=N) continue;
                if(list[i][j] != list[y][x]){
                    int temp_c = list[y][x];
                    list[y][x] = list[i][j];
                    list[i][j] = temp_c;
                    if(k==0){ //좌우로 바꿀 경우
                        int temp = list[y][0];
                        int count = 1;
                        for(int s=1; s<=j; s++){
                            if(temp!=list[y][s]){
                                temp = list[y][s];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }
                        
                        temp = list[y][x];
                        count = 1;
                        for(int s=x+1; s<N; s++){
                            if(temp!=list[y][s]){
                                temp = list[y][s];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }

                        temp = list[0][j];
                        count = 1;
                        for(int s=1; s<N; s++){
                            if(temp!=list[s][j]){
                                temp = list[s][j];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }

                        temp = list[0][x];
                        count = 1;
                        for(int s=1; s<N; s++){
                            if(temp!=list[s][x]){
                                temp = list[s][x];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }
                    }
                    else{ //상하로 바꿀 경우
                        int temp = list[0][j];
                        int count = 1;
                        for(int s=1; s<=i; s++){
                            if(temp!=list[s][j]){
                                temp = list[s][j];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }
                        
                        temp = list[y][x];
                        count = 1;
                        for(int s=y+1; s<N; s++){
                            if(temp!=list[s][x]){
                                temp = list[s][x];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }

                        temp = list[i][0];
                        count = 1;
                        for(int s=1; s<N; s++){
                            if(temp!=list[i][s]){
                                temp = list[i][s];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }

                        temp = list[y][0];
                        count = 1;
                        for(int s=1; s<N; s++){
                            if(temp!=list[y][s]){
                                temp = list[y][s];
                                count = 1;
                            }
                            else{
                                count++;
                                if(count>Max) Max = count;
                            }
                        }
                    }
                    temp_c = list[y][x];
                    list[y][x] = list[i][j];
                    list[i][j] = temp_c;
                }
            }
            if(Max == N){
                printf("%d\n", Max);
                return 0;
            }
        }
    }



    printf("%d\n", Max);
    return 0;
}