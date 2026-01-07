#include <stdio.h>

int N, pos = 0;
int list[64][64];
char str[5000];

void Quad(int y, int x, int M){
    int temp = 0;
    for(int i=y; i<y+M; i++){
        for(int j=x; j<x+M; j++){
            temp+=list[i][j];
        }  
    }
    if(temp == 0){
        str[pos++] = '0';
        return;
    }
    else if(temp == M*M){
        str[pos++] = '1';
        return;
    }
    int new_M = M/2;

    str[pos++] = '(';
    Quad(y, x, new_M);
    Quad(y, x+new_M, new_M);
    Quad(y+new_M , x, new_M);
    Quad(y+new_M, x+new_M, new_M);
    str[pos++] = ')';

    // if(M == N){
    //     int temp = 0;
    //     for(int i=0; i<M; i++){
    //         for(int j=0; j<M; j++){
    //             temp+=list[i][j];
    //         }  
    //     }
    //     if(temp == 0){
    //         str[pos++] = '0';
    //         return;
    //     }
    //     if(temp == N*N){
    //         str[pos++] = '1';
    //         return;
    //     }
    //     M = M/2;
    // }
    // int temp_x, temp_y;
    // int dx[4] = {0, M, 0, M};
    // int dy[4] = {0, 0, M, M};
    // for(int k=0; k<4; k++){
    //     temp_y = y+dy[k];
    //     temp_x = x+dx[k];
    //     temp = 0;
    //     for(int i=temp_y; i<temp_y+M; i++){
    //         for(int j=temp_x; j<temp_x+M; j++){
    //             temp+=list[i][j];
    //         }
    //     }
    //     if(temp == 0){
    //         str[pos++] ='0';
    //     }
    //     else if(temp == M*M){
    //         str[pos++] = '1';
    //     }
    //     else{
    //         Quad(temp_y, temp_x, M/2);
    //     }
    // }
    // str[pos++] = ')';
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &list[i][j]);
        }
    }

    Quad(0,0,N);
    str[pos] = '\0';
    printf("%s\n", str);
}