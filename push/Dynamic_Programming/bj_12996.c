#include <stdio.h>
#include <string.h>

#define MAX 1000000007

int S;
int list[3] = {0};
long long DP[51][51][51][51] = {0};
int C[7][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}};

void Find(){
    DP[S][list[0]][list[1]][list[2]] = 1;
    for(int i=S; i>0; i--){
        for(int j=list[0]; j>=0; j--){
            for(int k=list[1]; k>=0; k--){
                for(int l=list[2]; l>=0; l--){     
                    if(DP[i][j][k][l] == 0) continue;       
                    for(int m=0; m<7; m++){
                        int curr_a = j-C[m][0];
                        if(curr_a<0) continue;
                        int curr_b = k-C[m][1];
                        if(curr_b<0) continue;
                        int curr_c = l-C[m][2];
                        if(curr_c<0) continue;
                        DP[i-1][curr_a][curr_b][curr_c] += DP[i][j][k][l]%MAX;
                        DP[i-1][curr_a][curr_b][curr_c]%=MAX;
                    }
                }
            }
        }
    }
    printf("%d\n", DP[0][0][0][0]);
}

int main(void){
    scanf("%d", &S);
    for(int i=0; i<3; i++){
        scanf("%d", &list[i]);
    }
    Find();
    return 0;
}