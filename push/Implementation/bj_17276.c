#include <stdio.h>

int T;
int n, d;
int list[500][500];

void rotate_l(){
    int temp[500][500];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = list[i][j];
        }
    }
    
    int center = n/2;
    for(int i=0; i<n; i++){
        list[center][i] = temp[i][i];
        list[n-1-i][center] = temp[n-1-i][i];
        list[n-1-i][i] = temp[center][i];
        list[i][i] = temp[i][center];
    }
}

void rotate_r(){
    int temp[500][500];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = list[i][j];
        }
    }
    
    int center = n/2;
    for(int i=0; i<n; i++){
        list[i][center] = temp[i][i];
        list[center][i] = temp[n-1-i][i];
        list[i][i] = temp[center][i];
        list[i][n-1-i] = temp[i][center];
    }
}

int main(void){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &d);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &list[i][j]);
            }
        }
        while(d!=0){
            if(d<0){
                rotate_l();
                d+=45;
            }
            else{
                rotate_r();
                d-=45;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ", list[i][j]);
            }
            printf("\n");
        }
    }
}